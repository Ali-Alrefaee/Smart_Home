/**************************************************/
/*Desc   : interface file for LCD                 */
/*Author :Ahmed abo elnour                        */
/*Date   : 2 Sep 2023                             */
/*Version: 1.0V                                   */
/**************************************************/

#ifndef LCD_H
#define LCD_H
/*********************** Command to LCD Instruction Register ************************************************/
#define LCD_CLR                                             0x01
#define LCD_RETURN_HOME                         0x02               //Cursor Return To The Beginning
#define LCD_CURSOR_LEFT                            0x04              //Write Arabic
#define LCD_CURSOR_RIGHT                        0x06              //Write English
#define LCD_Display_RIGHT                         0x05              //Display Moving Right
#define LCD_Display_LEFT                             0x07             //Display Moving Left
#define LCD_CURSOR_POSITION_LEFT         0x10            //Neglect First Character
#define LCD_CURSOR_POSITION_RIGHT     0x14             //Leaves One Place Empty on the Left
#define LCD_Display_ONE_RIGHT                0x1C            //Display Moving Right One Place
#define LCD_Display_ONE_LEFT                   0x18             //Display Moving Left One Place
#define LCD_Display_OFF_CURSOR_OFF     0x08
#define LCD_Display_OFF_CURSOR_ON       0x0A
#define LCD_Display_ON_CURSOR_OFF       0x0C
#define LCD_Display_ON_BLINKING_OFF    0x0E
#define LCD_Display_OFF_BLINKING_ON    0x0F
#define LCD_LINE_1                                         0x80
#define LCD_LINE_2                                         0xC0

void LCD_vidInit(void);
void LCD_vidSendCmd(uint8 u8LcdNumCpy , uint8 u8CmdCpy);
void LCD_vidWriteData(uint8 u8LcdNumCpy , uint8 u8DataCpy);
void LCD_vidWriteString(uint8 u8LcdNumCpy , sint8* u8StringCpy);
void LCD_vidWriteDecimal(uint8 u8Numcpy , uint16 u16Res);
uint16 Pow(uint8 u16Res , uint8 Bas);

#endif
