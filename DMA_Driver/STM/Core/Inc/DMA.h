/*
 * DMA.h
 *
 *  Created on: Jan 4, 2022
 *      Author: abdoz
 */

#ifndef INC_DMA_H_
#define INC_DMA_H_


#define DMA_REG(PORT_ID,REG_ID) (unsigned int*)(PORT_ID + REG_ID)
//====== DMA1 Registers
#define DMA1_LISR 			DMA_REG(0x40026000, 0x0000)
#define DMA1_HISR 			DMA_REG(0x40026000, 0x0004)
#define DMA1_LIFCR 			DMA_REG(0x40026000, 0x0008)
#define DMA1_HIFCR 			DMA_REG(0x40026000, 0x000C)
#define DMA1_S0CR 			DMA_REG(0x40026000, 0x0010)
#define DMA1_S0NDTR 		DMA_REG(0x40026000, 0x0014)
#define DMA1_S0PAR 			DMA_REG(0x40026000, 0x0018)
#define DMA1_S0M0AR 		DMA_REG(0x40026000, 0x001C)
#define DMA1_S0M1AR 		DMA_REG(0x40026000, 0x0020)
#define DMA1_S0FCR 			DMA_REG(0x40026000, 0x0024)
//========== DMA2 Registers
#define DMA2_LISR 			DMA_REG(0x40026400, 0x0000)
#define DMA2_HISR 			DMA_REG(0x40026400, 0x0004)
#define DMA2_LIFCR 			DMA_REG(0x40026400, 0x0008)
#define DMA2_HIFCR 			DMA_REG(0x40026400, 0x000C)
#define DMA2_S0CR 			DMA_REG(0x40026400, 0x0010)
#define DMA2_S0NDTR 		DMA_REG(0x40026400, 0x0014)
#define DMA2_S0PAR 			DMA_REG(0x40026400, 0x0018)
#define DMA2_S0M0AR 		DMA_REG(0x40026400, 0x001C)
#define DMA2_S0M1AR 		DMA_REG(0x40026400, 0x0020)
#define DMA2_S0FCR 			DMA_REG(0x40026400, 0x0024)




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
void DMA_param(int *src,int *dest,int n,unsigned char trans_size,unsigned char trans_mode,unsigned char trans_type);
void DMA_start();




#endif /* INC_DMA_H_ */
