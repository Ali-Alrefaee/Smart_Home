#include <util/delay.h>
#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"

#include "LCD.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"

static uint8 InitFinshed=0;
void LCD_vidInit(void)
{
	uint8 u8CntrLoc ;
	uint8 u8CmdLoc =0;
	for(u8CntrLoc = 0 ;u8CntrLoc < LCD_MAX_NUM ; u8CntrLoc++ )
	{
		if (LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8Mode == LCD_8BIT_MODE)
		{

			_delay_ms(30);
			/*0b0011NF00*/
			u8CmdLoc = 0b00110000 |
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8LineNum<<3|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8Font<<2;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			_delay_ms(1);

			/*0b00001DCB*/
			u8CmdLoc = 0b00001000|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8DisplayStatus<< 2|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8CursorStatus<<1|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8BlinkStatus<<0;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			_delay_ms(1);

			LCD_vidSendCmd(u8CntrLoc , LCD_CLR);
			_delay_ms(2);

			/*0b000001 I/D SH*/
			u8CmdLoc = 0b00000100|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8In_DecrementMode<< 1|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8ShiftStatus<< 0;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			_delay_ms(2);

		}
		else
		{
			/*task initialize 4 bit mod ya fandem*/
			_delay_ms(30);
			/*0b00100000*/
			u8CmdLoc = 0b00100000;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			/*0b00100000*/
			u8CmdLoc = 0b00100000;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			/*0bNF000000*/
			u8CmdLoc = 0b00000000 |
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8LineNum<<7|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8Font<<6;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			_delay_ms(1);

			/*****Display ON/OFF Control*****/
			/*0b00000000*/
			u8CmdLoc = 0b00000000;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			/*0b1DCB0000*/
			u8CmdLoc = 0b10000000|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8DisplayStatus<< 6|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8CursorStatus<<5|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8BlinkStatus<<4;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			_delay_ms(1);

			/*****Display Clear******/
			/*0b00000000*/
			u8CmdLoc = 0b00000000;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			/*0b00010000*/
			u8CmdLoc = 0b00010000;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			_delay_ms(2);

			/*****Entry Mode Set*****/
			/*0b00000000*/
			u8CmdLoc = 0b00000000;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			//_delay_ms(1);
			/*0b01 I/D SH 0000*/
			u8CmdLoc = 0b01000000|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8In_DecrementMode<< 5|
					LCD_astrCfg[u8CntrLoc].strLcdInternalCfg.u8ShiftStatus<< 4;
			LCD_vidSendCmd(u8CntrLoc , u8CmdLoc);
			_delay_ms(2);

			InitFinshed=1;
		}


	}
}

void LCD_vidSendCmd(uint8 u8LcdNumCpy , uint8 u8CmdCpy)
{
	DIO_enuSetPinValue(LCD_astrCfg[u8LcdNumCpy].strLcdPinsCfg.u8RS,0);
	PutOnBus(u8LcdNumCpy , u8CmdCpy);

}

void LCD_vidWriteData(uint8 u8LcdNumCpy , uint8 u8DataCpy)
{
	DIO_enuSetPinValue(LCD_astrCfg[u8LcdNumCpy].strLcdPinsCfg.u8RS,1);
	PutOnBus(u8LcdNumCpy , u8DataCpy);

}

void LCD_vidWriteDecimal(uint8 u8LcdNumCpy , uint16 u8DecimalCpy)
{

	uint8 u8digit;
	uint8 u8DigCount=0;
	uint16 u16Rescpy = u8DecimalCpy;
	//NumOfDigit
	while(u8DecimalCpy != 0)
	{
		u8DecimalCpy /= 10;
		u8DigCount++;
	}

	//ConvertIntToChar
	for(uint8 u8CntrLoc = u8DigCount ;u8CntrLoc >= 1 ; u8CntrLoc--)
	{
		u8digit = (u16Rescpy / Pow(10 , u8CntrLoc-1 ));
		LCD_vidWriteData( u8LcdNumCpy , u8digit + 0x30);
		u16Rescpy -= u8digit * (Pow(10 , u8CntrLoc-1 ));
	}

}


void LCD_vidWriteString(uint8 u8LcdNumCpy , sint8* u8StringCpy)
{
	uint8 index=0;

	while(u8StringCpy[index] != '\0')
	{
		LCD_vidWriteData(u8LcdNumCpy , u8StringCpy[index]);
		index++;
	}
}


static void PutOnBus(uint8 u8LcdNumCpy , uint8 u8CmdOrDataCpy)
{
	uint8 u8CntrLoc;
	// wr 0 , en 1
	DIO_enuSetPinValue(LCD_astrCfg[u8LcdNumCpy].strLcdPinsCfg.u8RW,0);
	DIO_enuSetPinValue(LCD_astrCfg[u8LcdNumCpy].strLcdPinsCfg.u8EN,1);
	// mode 8
	if (LCD_astrCfg[u8LcdNumCpy].strLcdInternalCfg.u8Mode == LCD_8BIT_MODE)
	{

		for (u8CntrLoc = 0 ; u8CntrLoc < 8 ;u8CntrLoc ++)
		{
			DIO_enuSetPinValue(LCD_astrCfg[u8LcdNumCpy].strLcdPinsCfg.au8DataPins[u8CntrLoc] , GET_BIT(u8CmdOrDataCpy,u8CntrLoc));
		}

	}
	else
	{
		/* 4 bit mod task 3la 7drtk*/
		for (u8CntrLoc = 4 ; u8CntrLoc < 8 ;u8CntrLoc ++)
		{
			DIO_enuSetPinValue(LCD_astrCfg[u8LcdNumCpy].strLcdPinsCfg.au8DataPins[u8CntrLoc] , GET_BIT(u8CmdOrDataCpy,u8CntrLoc));
		}

		if(InitFinshed)
		{
			_delay_ms(1);
			DIO_enuSetPinValue(LCD_astrCfg[u8LcdNumCpy].strLcdPinsCfg.u8EN,0);
			//_delay_ms(1);
			DIO_enuSetPinValue(LCD_astrCfg[u8LcdNumCpy].strLcdPinsCfg.u8EN,1);
			for (u8CntrLoc = 0 ; u8CntrLoc < 4 ;u8CntrLoc ++)
			{
				DIO_enuSetPinValue(LCD_astrCfg[u8LcdNumCpy].strLcdPinsCfg.au8DataPins[u8CntrLoc+4] , GET_BIT(u8CmdOrDataCpy,u8CntrLoc));
			}
		}
	}



	// en 0
	_delay_ms(2);
	DIO_enuSetPinValue(LCD_astrCfg[u8LcdNumCpy].strLcdPinsCfg.u8EN,0);
	//_delay_ms(2);

}

uint16 Pow(uint8 u16Rescpy , uint8 u8Bascpy)
{
	uint16 u16POW = 1;
	for(uint8 u8CntrLoc=1 ; u8CntrLoc <= u8Bascpy ; u8CntrLoc++)
	{
		u16POW *= u16Rescpy;
	}
	return u16POW;
}

