/*
 * FLAME.c
 *
 *  Created on: Dec 13, 2023
 *      Author: WIN
 */

#include "STD_Types.h"
#include "FLAME.h"
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

 void flame_read(uint8 u8flameNumCpy, uint8 u8pinNum , fire_t *fire_status)
{
    logic_t logic = HIGH;


        DIO_enuReadPinValue (u8pinNum, &logic);
        if (logic == HIGH)
        {
            *fire_status = No_fire;
        }
        else
        {
            *fire_status = Is_fire;
        }
}


