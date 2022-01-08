/*
 * Author : Abdullah Mohamed
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
// Define adresses for Reg
#define ArraySize		6
int  	source[ArraySize]={1,1,1,1,1,1};
int 	destination[ArraySize]={0,0,0,0,0,0};

#include "GPIO.h"
#include "main.h"
#include "DMA.H"
void DMA_check()
{
	double_check();

}

int main(void) {
	GPIO_EnableClock(0);
	GPIO_Init(0, 5,OUTPUT, PUSH_PULL);
	GPIO_Init(0, 6,OUTPUT, PUSH_PULL);
	GPIO_Init(0, 7,OUTPUT, PUSH_PULL);

	DMA_init(1);
	DMA_param(source,destination,10,WORD,M_M,SINGLE) ;

	DMA_start();
	//*DMA_S0FCR	|= (1 << 2);			// disable direct mode
	//*DMA_S0FCR  &= ~(0x03);				// select the threshold to be 1/4 FIFO




  while (1){
  }
  return 0;
}
