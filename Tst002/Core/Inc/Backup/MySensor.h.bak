/*
 * MySensor.h
 *
 *  Created on: 2 mar 2022
 *      Author: andrus
 */
#ifndef SRC_MYSENSOR_H_
#define SRC_MYSENSOR_H_



#include "main.h"
#include "bmp280.h"
#include "dht.h"
#include "stm32f7xx_hal.h"



class MySensor {
	BMP280_HandleTypedef bmp280;

	uint16_t size;
	uint8_t  Data[256];
	bool     bme280p;  // "BME280" or "BMP280"

	bool use_dht = false;
	DHT_sensor * dht;


	void init_var();

public:
	float    pressure_pa, pressure, temperature, humidity, temperature_dht, humidity_dht;

	MySensor();
	MySensor( I2C_HandleTypeDef *  );

	void set_bmp( I2C_HandleTypeDef * );
	void set_dht( DHT_sensor * );

	bool get_data();

};



#endif /* SRC_MYSENSOR_H_ */
