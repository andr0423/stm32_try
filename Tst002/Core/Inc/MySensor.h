/*
 * MySensor.h
 *
 *  Created on: 2 mar. 2022 г.
 *      Author: andrus
 */
#ifndef SRC_MYSENSOR_H_
#define SRC_MYSENSOR_H_



#include "main.h"
#include "bmp280.h"




class MySensor {
	BMP280_HandleTypedef bmp280;
	//float    pressure_pa, pressure, temperature, humidity;
	uint16_t size;
	uint8_t  Data[256];
	bool     bme280p;  // "BME280" or "BMP280"

public:
	float    pressure_pa, pressure, temperature, humidity;

	MySensor( I2C_HandleTypeDef * hi2c1 );

	bool read_data();

};



#endif /* SRC_MYSENSOR_H_ */
