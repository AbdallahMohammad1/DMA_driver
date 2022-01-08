#include "DMA.h"
#include "GPIO.h"
#include "stdint.h"
int DMA_number;
unsigned int *DMA_registers [2][10] = {{DMA1_LISR, DMA1_HISR, DMA1_LIFCR, DMA1_HIFCR, DMA1_S0CR,
						  DMA1_S0NDTR, DMA1_S0PAR,DMA1_S0M0AR, DMA1_S0M1AR, DMA1_S0FCR},
		{DMA2_LISR, DMA2_HISR, DMA2_LIFCR, DMA2_HIFCR, DMA2_S0CR,
								  DMA2_S0NDTR, DMA2_S0PAR,DMA2_S0M0AR, DMA2_S0M1AR, DMA2_S0FCR}};
void DMA_init(int DMA)
{
	DMA_number = DMA;
	switch (DMA)
	{
	case(0):
		RCC_AHB1ENR |= 1 << 21;					// enable DMA2 clock
		*NVIC_ISER0	 = 1<<11;  // enable line 56 in NVIC in NVIC_ISER1 (which is bit 24 in the register)
		break;
	case(1):
		RCC_AHB1ENR |= 1 << 22;
		*NVIC_ISER1	 = 1<<24;
		break;
	}

}
void double_check()
{
	if((*DMA_registers[DMA_number][0] & 0x20))
	{
	GPIO_WritePin(0,5,1);
	}
	*DMA_registers[DMA_number][2] |= (1<<4);
}

void DMA_param(int *src,int *dest,int n,unsigned char trans_size,unsigned char trans_mode,unsigned char trans_type)
{
	*DMA_registers[DMA_number][4] = 0;
	*DMA_registers[DMA_number][4] 	|= (trans_mode << 6);		// memory to memory
	*DMA_registers[DMA_number][6]	 = (uint32_t)src;   // source address
	*DMA_registers[DMA_number][7]  = (uint32_t) dest;	// destination address
	*DMA_registers[DMA_number][5]	 = n;				// number of transfers
	*DMA_registers[DMA_number][4] 	|= (trans_size << 11);		// trans_size
	*DMA_registers[DMA_number][4] 	|= (trans_size << 13);		// trans_size
	*DMA_registers[DMA_number][4]   |= (0x03 << 9);			// increment mode according to MSIZE and PSIZE
	if (trans_type == SINGLE && trans_mode != M_M)
	{
		*DMA_registers[DMA_number][9] &= ~(1<<2);	// DMDIS enabled
		*DMA_registers[DMA_number][4]   &= ~(0x03 << 21);			// PBURST single
		*DMA_registers[DMA_number][4]   &= ~(0x03 << 23);			// MBURST single
		GPIO_WritePin(0,7,1);
	}
	else
	{
		GPIO_WritePin(0,6,1);

		*DMA_registers[DMA_number][9] |= (1<<2);	// DMDIS disabled
		*DMA_registers[DMA_number][4]   |= ( trans_type<< 21);			// PBURST burst 4/8/16
		*DMA_registers[DMA_number][4]   |= (trans_type << 23);			// MBURST burst 4/8/16
	}
}
void DMA_start()
{
	*DMA_registers[DMA_number][4]	|= (0x01 << 4);			// Transfer complete interrupt enable
	*DMA_registers[DMA_number][2]   = 0; 					//clear all interrupt flags
	*DMA_registers[DMA_number][4]	|= 1;					// enable stream 0
}
