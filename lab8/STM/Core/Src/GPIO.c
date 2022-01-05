/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */

#include "GPIO.h"

//#include "stm32f401cc_interface.h"

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0


#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

unsigned int *LOOKUP[2][10] ={{GPIOA_MODER,GPIOA_OTYPER,GPIOA_PUPDR,GPIOA_OSPEEDR,GPIOA_IDR,GPIOA_ODR,GPIOA_BSRR,GPIOA_LCKR,GPIOA_AFRL,GPIOA_AFRH},
							{GPIOB_MODER,GPIOB_OTYPER,GPIOB_PUPDR,GPIOB_OSPEEDR,GPIOB_IDR,GPIOB_ODR,GPIOB_BSRR,GPIOB_LCKR,GPIOB_AFRL,GPIOB_AFRH}};

void GPIO_EnableClock(int Portid) {
  switch (Portid) {
    case 0:
      RCC_AHB1ENR |= (0x01 << 0);
      break;
    case 1:
      RCC_AHB1ENR |= (0x01 << 1);
      break;
    default:
      break;
  }
}


void GPIO_Init(int Portid, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState) {
      // Configure moder register for pin direction
      *LOOKUP[Portid][0] &= ~(0x03 << 2 * PinNum);
      *LOOKUP[Portid][0] |= PinMode << 2 * PinNum;

      *LOOKUP[Portid][1] &= ~(1 << PinNum);
      *LOOKUP[Portid][1] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

      *LOOKUP[Portid][2] &= ~(0x03 << 2 * PinNum);
      *LOOKUP[Portid][2] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
      }


unsigned char GPIO_WritePin(int Portid, unsigned char PinNum,
                            unsigned char Data) {
  unsigned char result;
  if (((*LOOKUP[Portid][0] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
     if (Data) {
    	 *LOOKUP[Portid][5] |= (1 << PinNum);
        } else {
        	*LOOKUP[Portid][5] &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }
  return result;
}

unsigned char GPIO_ReadPin(int Portid, unsigned char PinNum) {
  unsigned char data = 0;
      data = (*LOOKUP[Portid][4] & (1 << PinNum)) >> PinNum;
  return data;
}

