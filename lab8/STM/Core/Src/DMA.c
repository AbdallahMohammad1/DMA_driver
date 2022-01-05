#include "DMA.h"
#include "GPIO.h"
#include "stdint.h"

void DMA_init()
{
	RCC_AHB1ENR |= 1 << 22;					// enable DMA2 clock
	*NVIC_ISER1	 = 1<<24;				// enable line 56 in NVIC in NVIC_ISER1 (which is bit 24 in the register)
}
void double_check()
{
	if((*DMA_LISR & 0x20))
	{
	GPIO_WritePin(0,5,1);
	}
}

void d()
{
		if((*DMA_LISR & 0x20))
		{
		GPIO_WritePin(0,5,1);
		}
		for(int i=0; i<5000000;i++);
}
void DMA_param(int *src,int *dest,int n,unsigned char trans_size,unsigned char trans_mode,unsigned char trans_type)
{
	*DMA_S0CR = 0;
	*DMA_S0CR 	|= (trans_mode << 6);		// memory to memory
	*DMA_S0PAR	 = (uint32_t)src;   // source address
	*DMA_S0M0AR  = (uint32_t) dest;	// destination address
	*DMA_S0NDTR	 = n;				// number of transfers
	*DMA_S0CR 	|= (trans_size << 11);		// trans_size
	*DMA_S0CR 	|= (trans_size << 13);		// trans_size
	*DMA_S0CR   |= (0x03 << 9);			// increment mode according to MSIZE and PSIZE
	if (trans_type == SINGLE && trans_mode != M_M)
	{
		*DMA_S0FCR &= ~(1<<2);	// DMDIS enabled
		*DMA_S0CR   &= ~(0x03 << 21);			// PBURST single
		*DMA_S0CR   &= ~(0x03 << 23);			// MBURST single
		GPIO_WritePin(0,7,1);
	}
	else
	{
		GPIO_WritePin(0,6,1);

		*DMA_S0FCR |= (1<<2);	// DMDIS disabled
		*DMA_S0CR   |= ( trans_type<< 21);			// PBURST burst 4/8/16
		*DMA_S0CR   |= (trans_type << 23);			// MBURST burst 4/8/16
	}
}
void DMA_start()
{
	*DMA_S0CR	|= (0x01 << 4);			// Transfer complete interrupt enable
	*DMA_LIFCR   = 0; 					//clear all interrupt flags
	*DMA_S0CR	|= 1;					// enable stream 0
}
