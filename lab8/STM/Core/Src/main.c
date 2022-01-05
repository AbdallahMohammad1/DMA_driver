/*
 * Author : Abdullah Mohamed
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
// Define adresses for Reg
#define ArraySize		6
int  	source[ArraySize]={1,1,1,1,1,1};
int 	destination[ArraySize]={0,0,0,0,0,0};
//static unsigned int 	DestinationArra[ArraySize]={0,0,0,0,0};

#include "GPIO.h"
#include "main.h"
#include "DMA.H"
#include "stdint.h"
void DMA_init()
{
	RCC_AHB1ENR |= 1 << 22;					// enable DMA2 clock
	*NVIC_ISER1	 = 1<<24;				// enable line 56 in NVIC in NVIC_ISER1 (which is bit 24 in the register)

}
void ddd()
{
	if((*DMA_LISR & 0x20))
	{
	GPIO_WritePin(0,5,destination[0]);
	}
}
void DMA_check()
{
	ddd();
	*DMA_LIFCR |= (1<<4);

}
void d()
{
		if((*DMA_LISR & 0x20))
		{
		GPIO_WritePin(0,5,destination[5]);
		}
		for(int i=0; i<5000000;i++);
}
void DMA_param(int *src,int *dest,int n,unsigned char trans_size)
{
	*DMA_S0CR = 0;
	*DMA_S0CR 	|= (0x01 << 7);		// memory to memory
	*DMA_S0PAR	 = (uint32_t)src;   // source address
	*DMA_S0M0AR  = (uint32_t) dest;	// destination address
	*DMA_S0NDTR	 = n;				// number of transfers
	*DMA_S0CR 	|= (trans_size << 11);		// trans_size
	*DMA_S0CR 	|= (trans_size << 13);		// trans_size
	*DMA_S0CR   |= (0x03 << 9);			// increment mode according to MSIZE and PSIZE

}
void DMA_start()
{
	*DMA_S0CR	|= (0x01 << 4);			// Transfer complete interrupt enable
	*DMA_LIFCR   = 0; 					//clear all interrupt flags
	*DMA_S0CR	|= 1;					// enable stream 0
}

int main(void) {
	GPIO_EnableClock(0);
	GPIO_Init(0, 5,OUTPUT, PUSH_PULL);
	DMA_init();
	DMA_param(source,destination,10,WORD) ;

	DMA_start();
	//*DMA_S0FCR	|= (1 << 2);			// disable direct mode
	//*DMA_S0FCR  &= ~(0x03);				// select the threshold to be 1/4 FIFO




  while (1){
		GPIO_WritePin(0,5,0);

  }
  return 0;
}
