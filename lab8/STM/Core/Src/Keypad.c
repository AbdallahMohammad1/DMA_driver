/*
 * Author : Abdullah Drwesh
 * Date   : 8/12/2021
 * Version: 1.0.0
 */
#include "Keypad.h"
#include "GPIO.h"
#include "main.h"
#include "stm32f401cc_interface.h"

unsigned char state =RELEASED;
unsigned char Key;
int pin1,pin2,pin3,pin4,pout1,pout2,pout3;
int input1,input2,input3,input4,output1,output2,output3;

void Keypdad_init(int portin1,int in1,int portin2,int in2,int portin3,int in3,int portin4,int in4,int portout1,int out1,int portout2,int out2,int portout3,int out3)
{
	  pin1=portin1;
	  pin2=portin2;
	  pin3=portin3;
	  pin4=portin4;
	  pout1=portin1;
	  pout2=portin2;
	  pout3=portin3;

	  input1 =in1;
	  input2 =in2;
	  input3 =in3;
	  input4 =in4;
	  output1 =out1;
	  output2 =out2;
	  output3 =out3;

	  GPIO_Init(portin1, in1, INPUT, PULL_UP);
	  GPIO_Init(portin2, in2, INPUT, PULL_UP);
	  GPIO_Init(portin3, in3, INPUT, PULL_UP);
	  GPIO_Init(portin4, in4, INPUT, PULL_UP);
	  GPIO_Init(portout1, out1, OUTPUT, PUSH_PULL);
	  GPIO_Init(portout2, out2, OUTPUT, PUSH_PULL);
	  GPIO_Init(portout3, out3, OUTPUT, PUSH_PULL);
}
unsigned char Keypad_GetKey()
{
	if(state == PRESSED)
	{
		state = RELEASED;
		return Key;
	}
}

void Keypad_manage()
{
 if(state == RELEASED)
 {
	 	   GPIO_WritePin(pout1, output1, 0);
	       GPIO_WritePin(pout2, output2, 1);
	       GPIO_WritePin(pout3, output3, 1);

	       if (GPIO_ReadPin(pin1, input1) == 0)
	       {
	           Key = ONE;
	           state =PRESSED;
	           KeypadCallouts_KeyPressNotificaton();
	       }
	       else if (GPIO_ReadPin(pin2, input2) == 0)
	       {
	    	   Key = FOUR;
	           state =PRESSED;
	           KeypadCallouts_KeyPressNotificaton();
	       }
	       else if (GPIO_ReadPin(pin3, input3) == 0)
	       {
	           Key = SEVEN;
	           state =PRESSED;
	           KeypadCallouts_KeyPressNotificaton();}

	       else if (GPIO_ReadPin(pin4, input4) == 0)
	       {
	           Key = ZERO;
	           state =PRESSED;
	           KeypadCallouts_KeyPressNotificaton();}
	       GPIO_WritePin(pout1, output1, 1);
	       GPIO_WritePin(pout2, output2, 0);
    	   GPIO_WritePin(pout3, output3, 1);

	       if (GPIO_ReadPin(pin1, input1) == 0)
	       {
	       	   Key = TWO;
	           state =PRESSED;
	           KeypadCallouts_KeyPressNotificaton();
	       }
	       else if (GPIO_ReadPin(pin2, input2) == 0)
	       {
	  	  	   Key = FIVE;
	      	   state =PRESSED;
	      	 KeypadCallouts_KeyPressNotificaton();
   	       }
	       else if (GPIO_ReadPin(pin3, input3) == 0)
	       {
	           Key = EIGHT;
	           state =PRESSED;
	           KeypadCallouts_KeyPressNotificaton();}
	       else if (GPIO_ReadPin(pin4, input4) == 0)
	       {
    	       Key = ZERO;
   	           state =PRESSED;
   	        KeypadCallouts_KeyPressNotificaton();}

	       GPIO_WritePin(pout1, output1, 1);
	       GPIO_WritePin(pout2, output2, 1);
    	   GPIO_WritePin(pout3, output3, 0);

	       if (GPIO_ReadPin(pin1, input1) == 0)
	       {
	       	   Key = THREE;
	           state =PRESSED;
	           KeypadCallouts_KeyPressNotificaton();
	       }
	       else if (GPIO_ReadPin(pin2, input2) == 0)
	       {
	  	  	   Key = SIX;
	      	   state =PRESSED;
	      	 KeypadCallouts_KeyPressNotificaton();
   	       }
	       else if (GPIO_ReadPin(pin3, input3) == 0)
	       {
	           Key = NINE;
	           state =PRESSED;
	           KeypadCallouts_KeyPressNotificaton();}
	       else if (GPIO_ReadPin(pin4, input4) == 0)
	       {
    	       Key = ZERO;
   	           state =PRESSED;
   	        KeypadCallouts_KeyPressNotificaton();}
	   //GPIO_WritePin('A', 0, 1);
	   //for (int i = 0; i < 300000; i++) {
	    // }
	   //GPIO_WritePin('A', 0, 0);
	   //for (int i = 0; i < 300000; i++) {
	   //  }
	   //state =PRESSED;
 }

}
