/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#ifndef GPIO_H
#define GPIO_H
#define GPIO_REG(PORT_ID,REG_ID) (unsigned int*)(PORT_ID + REG_ID)








#define RCC_AHB1ENR *GPIO_REG(0x40023800,0x30)
#define NVIC_ISER0 GPIO_REG(0xE000E100,0x00)
#define NVIC_ISER1 GPIO_REG(0xE000E100, 0x04)


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
