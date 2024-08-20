
#include "STD_Types.h"

#include "LCD_cfg.h"
#include "LCD_priv.h"



tstrLcdCfg  LCD_astrCfg[LCD_MAX_NUM]=
{
	/*LCD cfg num 0*/
	{
		/* Pin connections */
		{
			/*RS  , RW   , EN*/
			 0    , 1    , 2  ,
			/*D0  , D1 , D2 , D3 ,D4 , D5 , D6 , D7*/
			{ 24  , 25 , 26 , 27 ,3 , 4 , 5 , 6 }
		}
		,
		/*internal cfg */
		{
			LCD_4BIT_MODE  ,
			LCD_TWO_LINE     ,
			LCD_5X7                 ,
			LCD_DISPLAY_ON ,
			LCD_CURSOR_OFF,
		    LCD_CURSOR_BLINK_OFF,
			LCD_INCREMENT_MODE,
			LCD_SHIFT_OFF
		}
	}
};










