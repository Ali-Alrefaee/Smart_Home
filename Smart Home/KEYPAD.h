/******************************************/
/* Desc   : keypad interface.h file       */
/* Author : Ahmed Abo elnour              */
/* Date   : 08 Sep 2023                   */
/* version: 1.0V                          */
/******************************************/
#ifndef KEYPAD_H
#define KEYPAD_H


void KEYPAD_vidInit(void);

tenuErrorStatus KEYPAD_enuGetPressedKey(uint8 u8KeyNumCpy, uint8 * pu8PressedKeyCpy);

#endif