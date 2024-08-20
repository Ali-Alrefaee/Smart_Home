/*
 * RAIN_SENSOR.h
 *
 *  Created on: Dec 13, 2023
 *      Author: WIN
 */

#ifndef RAIN_SENSOR_H_
#define RAIN_SENSOR_H_

typedef enum {
     No_rain = 0,
	 Is_rain
}rain_t;

#define RAIN_HIGH    1
#define RAIN_LOW     0


void rain_read(uint8 u8rainNumCpy, uint8 u8pinNum , rain_t *rain_status);

#endif /* RAIN_SENSOR_H_ */
