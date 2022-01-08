/*
 * DMA.h
 *
 *  Created on: Jan 4, 2022
 *      Author: abdoz
 */

#ifndef INC_DMA_H_
#define INC_DMA_H_


#define DMA_REG(PORT_ID,REG_ID) (unsigned int*)(PORT_ID + REG_ID)
//#define RCC_AHB1ENR 		GPIO_REG(0x40023800, 0x30)  				// AHB1 enable bus clock
#define DMA1_LISR 			DMA_REG(0x40026000, 0x0000)				// DMA low interrupt status register (has the flags of the interrupts for streams 0 to 3)
#define DMA1_HISR 			DMA_REG(0x40026000, 0x0004)				// DMA high interrupt status register (has the flags of the interrupts for streams 4 to 7)
#define DMA1_LIFCR 			DMA_REG(0x40026000, 0x0008)				// DMA low interrupt flag clear register (used to clear the corresponding flag in the DMA_LISR register)
#define DMA1_HIFCR 			DMA_REG(0x40026000, 0x000C)				// DMA high interrupt flag clear register (used to clear the corresponding flag in the DMA_HISR register)
#define DMA1_S0CR 			DMA_REG(0x40026000, 0x0010)				// DMA stream 0 configuration register
#define DMA1_S0NDTR 		DMA_REG(0x40026000, 0x0014)				// DMA stream 0 number of data register (Number of data items to transfer or number of transfers to be precise)
#define DMA1_S0PAR 			DMA_REG(0x40026000, 0x0018)				// DMA stream 0 peripheral address register (stores the address of the source)
#define DMA1_S0M0AR 		DMA_REG(0x40026000, 0x001C)				// DMA stream 0 memory 0 address register (stores the address of the destination)
#define DMA1_S0M1AR 		DMA_REG(0x40026000, 0x0020)				// DMA stream 0 memory 1 address register (used in case of Double buffer mode instead of DMA_S0M0AR)
#define DMA1_S0FCR 			DMA_REG(0x40026000, 0x0024)				// DMA stream 0 FIFO control register
//==========
#define DMA2_LISR 			DMA_REG(0x40026400, 0x0000)				// DMA low interrupt status register (has the flags of the interrupts for streams 0 to 3)
#define DMA2_HISR 			DMA_REG(0x40026400, 0x0004)				// DMA high interrupt status register (has the flags of the interrupts for streams 4 to 7)
#define DMA2_LIFCR 			DMA_REG(0x40026400, 0x0008)				// DMA low interrupt flag clear register (used to clear the corresponding flag in the DMA_LISR register)
#define DMA2_HIFCR 			DMA_REG(0x40026400, 0x000C)				// DMA high interrupt flag clear register (used to clear the corresponding flag in the DMA_HISR register)
#define DMA2_S0CR 			DMA_REG(0x40026400, 0x0010)				// DMA stream 0 configuration register
#define DMA2_S0NDTR 		DMA_REG(0x40026400, 0x0014)				// DMA stream 0 number of data register (Number of data items to transfer or number of transfers to be precise)
#define DMA2_S0PAR 			DMA_REG(0x40026400, 0x0018)				// DMA stream 0 peripheral address register (stores the address of the source)
#define DMA2_S0M0AR 		DMA_REG(0x40026400, 0x001C)				// DMA stream 0 memory 0 address register (stores the address of the destination)
#define DMA2_S0M1AR 		DMA_REG(0x40026400, 0x0020)				// DMA stream 0 memory 1 address register (used in case of Double buffer mode instead of DMA_S0M0AR)
#define DMA2_S0FCR 			DMA_REG(0x40026400, 0x0024)				// DMA stream 0 FIFO control register
#define NVIC_ISER1 			DMA_REG(0xE000E100, 0x04)


#define BYTE ((unsigned char)0x00)
#define HALFWORD ((unsigned char)0x01)
#define WORD ((unsigned char)0x02)

#define P_M ((unsigned char)0x00)
#define M_P ((unsigned char)0x01)
#define M_M ((unsigned char)0x02)

#define SINGLE ((unsigned char)0x00)
#define BURST4 ((unsigned char)0x01)
#define BURST8 ((unsigned char)0x02)
#define BURST16 ((unsigned char)0x03)


void DMA_init(int DMA);
void double_check();
void d();
void DMA_param(int *src,int *dest,int n,unsigned char trans_size,unsigned char trans_mode,unsigned char trans_type);
void DMA_start();




#endif /* INC_DMA_H_ */
