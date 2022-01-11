#include "DMA.h"
#include "GPIO.h"
#include "stdint.h"

static int DMA_number;
unsigned int *DMA_registers [2][10] = {{DMA1_LISR, DMA1_HISR, DMA1_LIFCR, DMA1_HIFCR, DMA1_S0CR,
						  DMA1_S0NDTR, DMA1_S0PAR,DMA1_S0M0AR, DMA1_S0M1AR, DMA1_S0FCR},
		{DMA2_LISR, DMA2_HISR, DMA2_LIFCR, DMA2_HIFCR, DMA2_S0CR,
								  DMA2_S0NDTR, DMA2_S0PAR,DMA2_S0M0AR, DMA2_S0M1AR, DMA2_S0FCR}};
void DMA_init(int DMA)
{
	DMA_number = DMA;
	switch (DMA)
	{
	case(0): //DMA1
		RCC_AHB1ENR |= 1 << 21;					// enable DMA1 clock
		*NVIC_ISER0	 = 1<<11;  					//enable line 11 in NVIC_ISER0
		break;
	case(1): //DMA2
		RCC_AHB1ENR |= 1 << 22;  //enable DMA2 clock
		*NVIC_ISER1	 = 1<<24;  // enable line 56 in NVIC in NVIC_ISER1 (which is bit 24 in the register)
		break;
	}

}
int double_check()
{
	*DMA_registers[DMA_number][2] |= (1<<4);
	return (int)(*DMA_registers[DMA_number][0] & 0x20);
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

	*DMA_registers[DMA_number][4]   |= (trans_type << 21);			// PBURST single
	*DMA_registers[DMA_number][4]   |= (trans_type << 23);			// MBURST single

}
void DMA_start()
{
	*DMA_registers[DMA_number][4]	|= (0x01 << 4);			// Transfer complete interrupt enable
	*DMA_registers[DMA_number][4]	|= 1;					// enable stream 0
}
