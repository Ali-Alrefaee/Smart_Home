/******************************************/
/* Desc   : keypad private.h file         */
/* Author : Ahmed Abo elnour              */
/* Date   : 08 Sep 2023                   */
/* version: 1.0V                          */
/******************************************/

#ifndef KEYPAD_PRIV_H
#define KEYPAD_PRIV_H

typedef struct
{
	uint8 au8InputPins[KEYPAD_INPUT_MAX_NUM];
	uint8 au8OutputPins[KEYPAD_OUTPUT_MAX_NUM];
	uint8 KEYPAD_au8Rep[KEYPAD_INPUT_MAX_NUM][KEYPAD_OUTPUT_MAX_NUM];
	uint8 u8InputNum ;
	uint8 u8OutputNum ;
}tstrKeyPadCfg;

extern tstrKeyPadCfg KEYPAD_astrCfg[KEYPAD_MAX_NUM];

static void PutSequence (uint8 u8KeyNumCpy , uint8 u8SeqCpy);
static uint32 ReadSequence(uint8 u8KeyNumCpy );
static uint8 RepValue(uint8 u8KeyNumCpy ,  uint32 u32ValueCpy , uint8 u8SeqCpy);

#endif