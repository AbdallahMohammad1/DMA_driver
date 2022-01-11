/*
 * Author : Abdallah Mohammad
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
int  source[6]={1,1,1,1,1,1};
int destination[6]={0,0,0,0,0,0};
int src[100];
int dist[100];

#include "GPIO.h"
#include "main.h"
#include "DMA.H"
void DMA_check()
{
	int value = double_check();
	if (value)
	{
		//for(int c;c<6;c++)
		//{
			if (src[99] == dist[99])
			{
				GPIO_WritePin(0,5,1);
			}
		//}
	}
}

int main(void) {
	for (int i=0;i<100;i++)
	{
	src[i]=100*(i+1);
	}

	for (int i=0;i<100;i++)
	{
	dist[i]=0;
	}
	GPIO_EnableClock(0);
	GPIO_Init(0, 5,OUTPUT, PUSH_PULL);
	GPIO_Init(0, 6,OUTPUT, PUSH_PULL);
	GPIO_Init(0, 7,OUTPUT, PUSH_PULL);
	GPIO_Init(0, 8,OUTPUT, PUSH_PULL);
	GPIO_Init(0, 9,OUTPUT, PUSH_PULL);
	GPIO_Init(0, 10,OUTPUT, PUSH_PULL);
	DMA_init(1);
	DMA_param(src,dist,100,WORD,M_M,SINGLE) ;

	DMA_start();




  while (1){
//	  for(int n=0;n<1000000;n++);
//		GPIO_WritePin(0,5,0);

  }
  return 0;
}
