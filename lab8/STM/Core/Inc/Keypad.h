/*
 * Author : Abdullah Drwesh
 * Date   : 8/12/2021
 * Version: 1.0.0
 */

#ifndef KEYPAD_H
#define KEYPAD_H
#define PRESSED ((unsigned char)0x00)
#define RELEASED ((unsigned char)0x01)

#define ZERO ((unsigned char)0x00)
#define ONE ((unsigned char)0x01)
#define TWO ((unsigned char)0x02)
#define THREE ((unsigned char)0x03)
#define FOUR ((unsigned char)0x04)
#define FIVE ((unsigned char)0x05)
#define SIX ((unsigned char)0x06)
#define SEVEN ((unsigned char)0x07)
#define EIGHT ((unsigned char)0x08)
#define NINE ((unsigned char)0x09)
void KeypadCallouts_KeyPressNotificaton();
void Keypad_manage();
unsigned char Keypad_GetKey();
void Keypdad_init(int,int,int,int,int,int,int,int,int,int,int,int,int,int );

#endif /* KEYPAD_H */
