/**************************************************/
/*Desc   : App.c                                  */
/*Author : 3li Al_Refaee                          */
/*Date   : 26 Dec 2023                            */
/*Version: 2.4V                                   */
/**************************************************/

#include <util/delay.h>
#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "FLAME.h"
#include "SERVO.h"
#include "RAIN_SENSOR.h"


uint8 state=0;
uint8 Button=1;
uint8 DIGIT = '\0';
uint8 n = 1, i, x = 0, NUMBER_OF_WRONG_PASS = 0;
uint8 PASSWORD_RESRVED[4] = {6, 6, 6, 6};
uint8 PASSWORD [4];
int flag = 0;
fire_t flame_logic;
//light_t ldr_logic;
rain_t rain_logic;



int main(void)
{


	DIO_vidInit();
	LCD_vidInit();
	servo_init();
	KEYPAD_vidInit();

	DIO_enuSetPinPullUp(15 , 1);

	while(1)
	{

		if ( n == 1 )
		{
			LCD_vidSendCmd(0,LCD_CLR);
			LCD_vidWriteString(0, "Enter Password :");
			LCD_vidSendCmd(0,LCD_LINE_2 ); // TO SET CURSOR TO SECOND LINE
			//_delay_ms (100);
			flag = 0;
		}

		while ( n < 6 )
		{

			do{
				KEYPAD_enuGetPressedKey(0 , &DIGIT);
				//_delay_ms(150);

			}while(DIGIT == 0xFF);
			//_delay_ms (150);
			if ( (DIGIT != '\0')&& (DIGIT != '#') && (DIGIT != '*') && (n != 5) )
			{
				LCD_vidWriteData(0, '*');
				PASSWORD[n - 1] = DIGIT;
				DIGIT = '\0';
				n++;
				_delay_ms (200);
			}
			else  if( '#' == DIGIT )
			{
				n++;
				DIGIT = '\0';
				if ( n < 6 )
				{
					/* wrong password*/
					LCD_vidSendCmd(0,LCD_CLR);
					LCD_vidWriteString (0, "Wrong Password!!");
					//led_on (&led_2);
					//led_off (&led_1);
					NUMBER_OF_WRONG_PASS ++;
					flag = 0;
					break;
				}
				else
				{
					//compare entered password with the actual password//
					for ( i = 0; i < 4; i++ )
					{
						if ( PASSWORD[i] == PASSWORD_RESRVED[i] )
						{
							x ++;
						}
						else
						{
							break;
						}
					}

					if ( x == 4 )
					{
						/* correct password ---> open door*/
						LCD_vidSendCmd(0,LCD_CLR);
						LCD_vidWriteString (0, " Welcome Home");
						flag = 1;
						//led_on (&led_1);
						//led_off (&led_2);
						NUMBER_OF_WRONG_PASS = 0;
						x=0;
						servo_ON ();
						_delay_ms (2000);
						servo_OFF ();
						n=10;
						break;

					}
					else
					{
						/* wrong password*/
						LCD_vidSendCmd(0,LCD_CLR);
						LCD_vidWriteString (0, "Wrong Password!!");
						//led_on (&led_2);
						//led_off (&led_1);
						NUMBER_OF_WRONG_PASS ++;
						flag = 0;

					}
				}
			}
		}

		_delay_ms(1000);
		LCD_vidSendCmd(0,LCD_CLR);

		if ( NUMBER_OF_WRONG_PASS )
		{
			n = 1;
			x = 0;
			DIGIT = '\0';
			if ( 3 == NUMBER_OF_WRONG_PASS )
			{
				/* BUZZER WHEN USER INTERS WRONG PASS 3 TIMES*/
				//led_on (&led_3);
				LCD_vidSendCmd(0 , LCD_LINE_1+4);
				LCD_vidWriteString(0 , "warning !!!");
				LCD_vidSendCmd(0 , LCD_LINE_2+4);
				LCD_vidWriteString(0 , "robbery");
				DIO_enuSetPinValue(24 , 1);
				while(0 != Button)
				{
					DIO_enuReadPinValue(15 , &Button);
					//KEYPAD_enuGetPressedKey (0, &DIGIT);
				}
				//n = 6;
				Button=1;
				DIO_enuSetPinValue(24 , 0);
				NUMBER_OF_WRONG_PASS = 0;
			}
		}


		while (flag == 1)
		{
			flame_read(0 , 7 , &flame_logic);
			if ( (flame_logic == Is_fire) )
			{

				DIO_enuSetPinValue(24 , 1);
				LCD_vidSendCmd(0,LCD_CLR);
				LCD_vidSendCmd(0 , LCD_LINE_1+2);
				LCD_vidWriteString(0 , "The house is");
				LCD_vidSendCmd(0 , LCD_LINE_2+3);
				LCD_vidWriteString(0 , " burning !!");
				DIO_enuReadPinValue(15 , &Button);
				while(0 != Button)
				{
					DIO_enuReadPinValue(15 , &Button);
				}
				state=0;
				DIO_enuSetPinValue(24 , 0);
			}

			/*******************************************************/
			rain_read(0 , 10 , &rain_logic);
			if((flame_logic == No_fire)&&(rain_logic == No_rain))
			{
				if(state==1)
				{
					LCD_vidSendCmd(0,LCD_CLR);
					LCD_vidWriteString(0 , "HOUSE:Controlled");
					LCD_vidSendCmd(0 , LCD_LINE_2);
					LCD_vidWriteString(0 , "Weather : RAINY");
					state=0;
				}
			}
			else
			{
				if(state==0)
				{
					LCD_vidSendCmd(0,LCD_CLR);
					LCD_vidWriteString(0 , "HOUSE:Controlled");
					LCD_vidSendCmd(0 , LCD_LINE_2);
					LCD_vidWriteString(0 , "Weather : COOL");
					state=1;
				}
			}

			KEYPAD_enuGetPressedKey (0, &DIGIT);
			if('*' == DIGIT)
			{
				n=1;
				state=0;
				break;
			}
		}


	}

	return  0 ;
}

