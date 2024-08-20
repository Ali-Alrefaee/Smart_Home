#include <util/delay.h>
#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"

#include "KEYPAD.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"

void KEYPAD_vidInit(void)
{
	uint8 u8CntrLoc ,u8Cntr1Loc;
	for (u8CntrLoc = 0 ; u8CntrLoc < KEYPAD_MAX_NUM ; u8CntrLoc++)
	{
		for(u8Cntr1Loc = 0 ; u8Cntr1Loc < KEYPAD_astrCfg[u8CntrLoc].u8InputNum ; u8Cntr1Loc++)
		{
			DIO_enuSetPinPullUp(KEYPAD_astrCfg[u8CntrLoc].au8InputPins[u8Cntr1Loc] , 1);
		}
	}
}

tenuErrorStatus  KEYPAD_enuGetPressedKey(uint8 u8KeyNumCpy, uint8 * pu8PressedKeyCpy)
{
	tenuErrorStatus enuResLoc = E_OK ;
	uint8 u8SeqNumLoc ;
	uint32 u32ReadsLoc = 0 ;
	uint8 u8RepLoc;
	
	if (u8KeyNumCpy >= KEYPAD_MAX_NUM)
	{
		enuResLoc = OUT_OF_RANG ;
	}
	else if (pu8PressedKeyCpy == NULL)
	{
		enuResLoc = IS_NULL_POINTER ;
	}
	else
	{
		for(u8SeqNumLoc = 0 ; u8SeqNumLoc < KEYPAD_astrCfg[u8KeyNumCpy].u8OutputNum ;u8SeqNumLoc++)
		{
			 // sequence 
			 PutSequence(u8KeyNumCpy,u8SeqNumLoc);
			 _delay_ms(10);
			 // read input 
			 u32ReadsLoc = ReadSequence(u8KeyNumCpy);
			 _delay_ms(10);
			 // repesent  0xFF
			 u8RepLoc = RepValue(u8KeyNumCpy ,u32ReadsLoc,u8SeqNumLoc);
			 // check != 0xFF break
			 if (u8RepLoc!=0xFF)
			 {
				
				 break;
			 }
			 
			
		}
		
   
 	}
	 *pu8PressedKeyCpy = u8RepLoc ;
	return enuResLoc ;
	
}


static void PutSequence (uint8 u8KeyNumCpy , uint8 u8SeqCpy)
{
	uint8 u8CntrLoc ;
	for (u8CntrLoc = 0 ;u8CntrLoc < KEYPAD_astrCfg[u8KeyNumCpy].u8OutputNum ;u8CntrLoc++)
	{
		if (u8SeqCpy == u8CntrLoc )
		{
			DIO_enuSetPinValue(KEYPAD_astrCfg[u8KeyNumCpy].au8OutputPins[u8CntrLoc],0);
		}
		else
		{
			DIO_enuSetPinValue(KEYPAD_astrCfg[u8KeyNumCpy].au8OutputPins[u8CntrLoc],1);
		}
	}
}

static uint32 ReadSequence(uint8 u8KeyNumCpy )
{
	uint8 u8CntrLoc  ;
	uint8 u8ReadsLoc ;
	uint32 u32ReturnLoc =0 ;
	for (u8CntrLoc = 0 ;u8CntrLoc < KEYPAD_astrCfg[u8KeyNumCpy].u8InputNum ; u8CntrLoc++ )
	{
		DIO_enuReadPinValue(KEYPAD_astrCfg[u8KeyNumCpy].au8InputPins[u8CntrLoc] , &u8ReadsLoc);
		u32ReturnLoc|= u8ReadsLoc<< u8CntrLoc;
	}
	return u32ReturnLoc;
}


static uint8 RepValue(uint8 u8KeyNumCpy ,  uint32 u32ValueCpy , uint8 u8SeqCpy)
{
	uint8 u8CntrLoc ;
	uint8 u8ReturnLoc = 0xFF ;
	for (u8CntrLoc = 0 ; u8CntrLoc < KEYPAD_astrCfg[u8KeyNumCpy].u8InputNum ; u8CntrLoc++)
	{
		if (GET_BIT(u32ValueCpy,u8CntrLoc) == 0)
		{
			u8ReturnLoc = KEYPAD_astrCfg[u8KeyNumCpy].KEYPAD_au8Rep[u8CntrLoc][u8SeqCpy];
			break ;
		}
	}
	return u8ReturnLoc ;

	
	
}
