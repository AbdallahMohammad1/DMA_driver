/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#ifndef GPIO_H
#define GPIO_H
#define GPIO_REG(PORT_ID,REG_ID) (unsigned int*)(PORT_ID + REG_ID)
//#define RCC_AHB1ENR 		GPIO_REG(0x40023800, 0x30)  				// AHB1 enable bus clock
#define DMA_LISR 			GPIO_REG(0x40026400, 0x0000)				// DMA low interrupt status register (has the flags of the interrupts for streams 0 to 3)
#define DMA_HISR 			GPIO_REG(0x40026400, 0x0004)				// DMA high interrupt status register (has the flags of the interrupts for streams 4 to 7)
#define DMA_LIFCR 			GPIO_REG(0x40026400, 0x0008)				// DMA low interrupt flag clear register (used to clear the corresponding flag in the DMA_LISR register)
#define DMA_HIFCR 			GPIO_REG(0x40026400, 0x000C)				// DMA high interrupt flag clear register (used to clear the corresponding flag in the DMA_HISR register)
#define DMA_S0CR 			GPIO_REG(0x40026400, 0x0010)				// DMA stream 0 configuration register
#define DMA_S0NDTR 			GPIO_REG(0x40026400, 0x0014)				// DMA stream 0 number of data register (Number of data items to transfer or number of transfers to be precise)
#define DMA_S0PAR 			GPIO_REG(0x40026400, 0x0018)				// DMA stream 0 peripheral address register (stores the address of the source)
#define DMA_S0M0AR 			GPIO_REG(0x40026400, 0x001C)				// DMA stream 0 memory 0 address register (stores the address of the destination)
#define DMA_S0M1AR 			GPIO_REG(0x40026400, 0x0020)				// DMA stream 0 memory 1 address register (used in case of Double buffer mode instead of DMA_S0M0AR)
#define DMA_S0FCR 			GPIO_REG(0x40026400, 0x0024)				// DMA stream 0 FIFO control register
#define NVIC_ISER1 			GPIO_REG(0xE000E100, 0x04)





#define USART1_CR1 GPIO_REG(0x40011000,0x0C)
#define USART2_CR1 GPIO_REG(0x40004400,0x0C)
#define USART2_BRR GPIO_REG(0x40004400,0x08)
#define USART2_SR GPIO_REG(0x40004400,0x00)
#define USART2_DR GPIO_REG(0x40004400,0x04)


#define RCC_AHB1ENR *GPIO_REG(0x40023800,0x30)
#define RCC_APB1ENR GPIO_REG(0x40023800,0x40)
#define RCC_APB2ENR GPIO_REG(0x40023800,0x44)
#define SYSCFG (unsigned int*)(0x40013800)
#define SYSCFG_EXTICR1 GPIO_REG(0x40013800,0x08)
#define EXTI_IMR GPIO_REG(0x40013C00,0x00)
#define EXTI_FTSR GPIO_REG(0x40013C00,0x0C)
#define EXTI_PR GPIO_REG(0x40013C00,0x14)
#define NVIC_ISER0 GPIO_REG(0xE000E100,0x00)

//0x4001 3800  SYSCFG
#define GPIOA_MODER GPIO_REG(0x40020000,0x00)
#define GPIOA_OTYPER GPIO_REG(0x40020000,0x04)
#define GPIOA_PUPDR GPIO_REG(0x40020000,0x0C)
#define GPIOA_OSPEEDR GPIO_REG(0x40020000,0x08)
#define GPIOA_IDR GPIO_REG(0x40020000,0x10)
#define GPIOA_ODR GPIO_REG(0x40020000,0x14)
#define GPIOA_BSRR GPIO_REG(0x40020000,0x18)
#define GPIOA_LCKR GPIO_REG(0x40020000,0x1C)
#define GPIOA_AFRL GPIO_REG(0x40020000,0x20)
#define GPIOA_AFRH GPIO_REG(0x40020000,0x24)

#define GPIOB_MODER GPIO_REG(0x40020400,0x00)
#define GPIOB_OTYPER GPIO_REG(0x40020400,0x04)
#define GPIOB_PUPDR GPIO_REG(0x40020400,0x0C)
#define GPIOB_OSPEEDR GPIO_REG(0x40020400,0x08)
#define GPIOB_IDR GPIO_REG(0x40020400,0x10)
#define GPIOB_ODR GPIO_REG(0x40020400,0x14)
#define GPIOB_BSRR GPIO_REG(0x40020400,0x18)
#define GPIOB_LCKR GPIO_REG(0x40020400,0x1C)
#define GPIOB_AFRL GPIO_REG(0x40020400,0x20)
#define GPIOB_AFRH GPIO_REG(0x40020400,0x24)


// Result Status
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Resistor modes
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

void GPIO_EnableClock(int Portid);

void GPIO_Init(int PortName, unsigned char PinNum, unsigned char PinDir,
               unsigned char DefaultState);
unsigned char GPIO_WritePin(int Port, unsigned char PinNum,
                            unsigned char Data);

unsigned char GPIO_ReadPin(int PortName, unsigned char PinNum);

#endif /* GPIO_H */
