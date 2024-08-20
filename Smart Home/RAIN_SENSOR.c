/*
 * RAIN_SENSOR.c
 *
 *  Created on: Dec 13, 2023
 *      Author: WIN
 */
#include "STD_Types.h"
#include "RAIN_SENSOR.h"
#include "DIO.h"

/**
 * flame_read - function that get if there is fire or not
 *
 * @param fire_pin - an object of the pin connected to the micro_controller
 * @param fire_status - returns HIGH if there is Fire
 *                      and returns LOW if there is no Fire
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to
 */

void rain_read(uint8 u8rainNumCpy, uint8 u8pinNum , rain_t *rain_status)
{

		uint8 logic=0;

        DIO_enuReadPinValue (u8pinNum, &logic);
        if (logic == RAIN_HIGH)
        {
            *rain_status = Is_rain;
        }
        else
        {
            *rain_status = No_rain;
        }
}



