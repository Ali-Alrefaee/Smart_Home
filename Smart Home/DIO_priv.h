/**************************************************/
/*Desc   : priv file for DIO                      */
/*Author :3li Al_Refaee                        */
/*Date   : 25 Aug 2023                            */
/*Version: 1.0V                                   */
/**************************************************/

#ifndef DIO_PRIV_H
#define DIO_PRIV_H

#define INPUT      0
#define OUTPUT  1

#define DDRA   *((volatile uint8 *) 0x3A )     
#define ODRA   *((volatile uint8 *) 0x3B )
#define IDRA   *((volatile uint8 *) 0x39 )

#define DDRB   *((volatile uint8 *) 0x37 )
#define ODRB   *((volatile uint8 *) 0x38 )
#define IDRB   *((volatile uint8 *) 0x36 )

#define DDRC   *((volatile uint8 *) 0x34 )
#define ODRC   *((volatile uint8 *) 0x35 )
#define IDRC   *((volatile uint8 *) 0x33 )

#define DDRD   *((volatile uint8 *) 0x31 )
#define ODRD   *((volatile uint8 *) 0x32 )
#define IDRD   *((volatile uint8 *) 0x30 )


#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)             CONC_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_help(b7,b6,b5,b4,b3,b2,b1,b0)   0b##b7##b6##b5##b4##b3##b2##b1##b0



#ifndef DIO_DIR_PIN_24
#define DIO_DIR_PIN_24 INPUT
#endif

#endif /*Gaurd*/
