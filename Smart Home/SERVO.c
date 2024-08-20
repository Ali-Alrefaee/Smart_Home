/*
 * SERVO.c
 *
 *  Created on: Dec 13, 2023
 *      Author: WIN
 */

#include <util/delay.h>
#include "SERVO.h"

void servo_init(void)
{

	DIO_enuSetPinValue(9 , 1);
  // Delay for the high state duration (0.01 seconds)
    _delay_ms(1.5);
  // Set the output pin low
    DIO_enuSetPinValue(9 , 0);
  // Delay for the low state duration (0.01 seconds)
    _delay_ms(18.5);

}

void servo_ON(void)
{
	// Set the output pin high
	DIO_enuSetPinValue(9 , 1);
	// Delay for the high state duration (0.01 seconds)
	_delay_ms(2);   //+90
	// Set the output pin low
	DIO_enuSetPinValue(9 , 0);
	// Delay for the low state duration (0.01 seconds)
	_delay_ms(18);

}
void servo_OFF(void)
{
	DIO_enuSetPinValue(9 , 1);
	_delay_ms(1);   //-90

	DIO_enuSetPinValue(9 , 0);
	// Delay for the low state duration (0.01 seconds)
	_delay_ms(19);
}

