#ifndef LCD_PRIV_H
#define LCD_PRIV_H

#define LCD_8BIT_MODE   1
#define LCD_4BIT_MODE   0

#define LCD_ONE_LINE    0
#define LCD_TWO_LINE    1

#define LCD_5X7         0
#define LCD_5X11        1

#define LCD_DISPLAY_OFF 0
#define LCD_DISPLAY_ON  1


#define LCD_CURSOR_OFF 0
#define LCD_CURSOR_ON  1

#define LCD_CURSOR_BLINK_OFF   0
#define LCD_CURSOR_BLINK_ON     1

#define LCD_INCREMENT_MODE   1               //(I/D)  For English
#define LCD_DECREMENT_MODE   0             //(I/D)   For Arabic       Must change in address of  ( LCD_LINE_1 and  LCD_LINE_2)  in LCD.h

#define LCD_SHIFT_OFF  0
#define LCD_SHIFT_ON   1

typedef struct {
	uint8 u8RS ;
	uint8 u8RW ;
	uint8 u8EN ;
	uint8 au8DataPins[8];
}tstrLcdPinsCfg;

typedef struct {
	uint8 u8Mode                                  :1;
	uint8 u8LineNum                            :1;
	uint8 u8Font                                    :1;
	uint8 u8DisplayStatus                    :1;
	uint8 u8CursorStatus                      :1;
	uint8 u8BlinkStatus                         :1;
	uint8 u8In_DecrementMode          :1;
	uint8 u8ShiftStatus                          :1;
}tstrLcdInternalCfg;


typedef struct 
{
	tstrLcdPinsCfg     strLcdPinsCfg;
	tstrLcdInternalCfg strLcdInternalCfg ;
}tstrLcdCfg ;

extern tstrLcdCfg  LCD_astrCfg[LCD_MAX_NUM] ;

static void PutOnBus(uint8 u8LcdNumCpy , uint8 u8CmdOrDataCpy);

#endif
