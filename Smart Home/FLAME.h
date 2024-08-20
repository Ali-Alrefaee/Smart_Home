/*
 * FLAME.h
 *
 *  Created on: Dec 13, 2023
 *      Author: WIN
 */

#ifndef FLAME_H_
#define FLAME_H_


typedef enum {
    Is_fire = 0,
    No_fire
}fire_t;

typedef enum {
    LOW = 0,
	HIGH
}logic_t;

void flame_read(uint8 u8flameNumCpy, uint8 u8pinNum , fire_t *fire_status);

#endif /* FLAME_H_ */
