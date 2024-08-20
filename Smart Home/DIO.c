#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"
#include "DIO_cfg.h"
#include "DIO_priv.h"

void DIO_vidInit(void)
{
	DDRA = CONC(DIO_DIR_PIN_7,DIO_DIR_PIN_6,DIO_DIR_PIN_5,DIO_DIR_PIN_4,DIO_DIR_PIN_3,DIO_DIR_PIN_2,DIO_DIR_PIN_1,DIO_DIR_PIN_0);
	DDRB = CONC(DIO_DIR_PIN_15,DIO_DIR_PIN_14,DIO_DIR_PIN_13,DIO_DIR_PIN_12,DIO_DIR_PIN_11,DIO_DIR_PIN_10,DIO_DIR_PIN_9,DIO_DIR_PIN_8);
	DDRC = CONC(DIO_DIR_PIN_23,DIO_DIR_PIN_22,DIO_DIR_PIN_21,DIO_DIR_PIN_20,DIO_DIR_PIN_19,DIO_DIR_PIN_18,DIO_DIR_PIN_17,DIO_DIR_PIN_16 );
	DDRD = CONC(DIO_DIR_PIN_31,DIO_DIR_PIN_30,DIO_DIR_PIN_29,DIO_DIR_PIN_28,DIO_DIR_PIN_27,DIO_DIR_PIN_26,DIO_DIR_PIN_25,DIO_DIR_PIN_24 );
	
	
}

tenuErrorStatus DIO_enuSetPinDir   (uint8 u8PinNumCpy ,uint8  u8PinDirCpy)
{
	tenuErrorStatus enuErrorStatusLoc;
	if(u8PinNumCpy > 31 || u8PinDirCpy > 1)
	{
		enuErrorStatusLoc = OUT_OF_RANG ;
	}
	else
	{
		if(u8PinNumCpy <=7)
		{
			/*DDRA*/
			if (u8PinDirCpy == 0)
			{
				// clear pin 
				CLR_BIT(DDRA,u8PinNumCpy);
			}
			else
			{
				// set pin
				SET_BIT(DDRA,u8PinNumCpy);
			}
		}
		else if (u8PinNumCpy <=15)
		{
			/*DDRB*/
			u8PinNumCpy =u8PinNumCpy%8;
			if (u8PinDirCpy == 0)
			{
				// clear pin 
				CLR_BIT(DDRB,u8PinNumCpy);
			}
			else
			{
				// set pin
				SET_BIT(DDRB,u8PinNumCpy);
			}
		}
		else if (u8PinNumCpy <=23)
		{
			/*DDRC*/
			u8PinNumCpy =u8PinNumCpy%8;
			if (u8PinDirCpy == 0)
			{
				// clear pin 
				CLR_BIT(DDRC,u8PinNumCpy);
			}
			else
			{
				// set pin
				SET_BIT(DDRC,u8PinNumCpy);
			}
		}
		else
		{
			/*DDRD*/
			u8PinNumCpy =u8PinNumCpy%8;
			if (u8PinDirCpy == 0)
			{
				// clear pin 
				CLR_BIT(DDRD,u8PinNumCpy);
			}
			else
			{
				// set pin
				SET_BIT(DDRD,u8PinNumCpy);
			}
		}
	 enuErrorStatusLoc = E_OK ;
	}
	return enuErrorStatusLoc;
}

tenuErrorStatus DIO_enuSetPinValue (uint8 u8PinNumCpy ,uint8  u8PinStatusCpy)
{
	tenuErrorStatus enuErrorStatusLoc ;
	if (u8PinNumCpy > 31 || u8PinStatusCpy > 1)
	{
		enuErrorStatusLoc = OUT_OF_RANG ;
	}
    else
    {
		if(u8PinNumCpy <= 7)
        {
			/*ODRA*/
			if (u8PinStatusCpy == 0)
			{
				//CLR BIT
				CLR_BIT(ODRA , u8PinNumCpy);
			}
			else 
			{
				//SET BIT
				SET_BIT(ODRA , u8PinNumCpy);
			}
		}
        else if(u8PinNumCpy <= 15)
        {
			/*ODRB*/
			if (u8PinStatusCpy == 0)
			{
				//CLR BIT
				CLR_BIT(ODRB , (u8PinNumCpy%8));
			}
			else 
			{
				//SET BIT
				SET_BIT(ODRB , (u8PinNumCpy%8));
			}
		}
        else if(u8PinNumCpy <= 23)
        {
			/*ODRC*/
			if (u8PinStatusCpy == 0)
			{
				//CLR BIT
				CLR_BIT(ODRC , (u8PinNumCpy%8));
			}
			else 
			{
				//SET BIT
				SET_BIT(ODRC , (u8PinNumCpy%8));
			}
		}
		else
		{
			/*ODRD*/
			if (u8PinStatusCpy == 0)
			{
				//CLR BIT
				CLR_BIT(ODRD , (u8PinNumCpy%8));
			}
			else 
			{
				//SET BIT
				SET_BIT(ODRD , (u8PinNumCpy%8));
			}
		}

        enuErrorStatusLoc = E_OK;
		

	}
	return enuErrorStatusLoc ;
}
tenuErrorStatus DIO_enuReadPinValue(uint8 u8PinNumCpy ,uint8* pu8PinValueCpy)
{
	tenuErrorStatus enuErrorStatusLoc  ;
	if(u8PinNumCpy > 31)
	{
		enuErrorStatusLoc = OUT_OF_RANG ;	
	}
	else if (pu8PinValueCpy == NULL)
	{
		enuErrorStatusLoc = IS_NULL_POINTER; 
	}
	else
	{
		if(u8PinNumCpy <= 7)
		{
			/*IDRA*/
			*pu8PinValueCpy = GET_BIT(IDRA ,u8PinNumCpy );
		}
		else if(u8PinNumCpy <= 15)
		{
			/*IDRB*/
			
			*pu8PinValueCpy = GET_BIT(IDRB ,(u8PinNumCpy%8) );
		}
		else if(u8PinNumCpy <= 23)
		{
			/*IDRC*/
			
			*pu8PinValueCpy = GET_BIT(IDRC ,(u8PinNumCpy%8) );
		}
		else 
		{
			/*IDRD*/
			
			*pu8PinValueCpy = GET_BIT(IDRD ,(u8PinNumCpy%8) );
		}
		enuErrorStatusLoc = E_OK ;
	}
	
	return enuErrorStatusLoc ;
}
tenuErrorStatus DIO_enuSetPinPullUp(uint8 u8PinNumCpy ,uint8  u8PullupStatusCpy)
{
   return DIO_enuSetPinValue(u8PinNumCpy ,u8PullupStatusCpy);	
}

