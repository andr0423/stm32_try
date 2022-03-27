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




class MySensor {
	BMP280_HandleTypedef bmp280;
	//float    pressure_pa, pressure, temperature, humidity;

	uint16_t size;
	uint8_t  Data[256];
	bool     bme280p;  // "BME280" or "BMP280"

	//vector<float> arr_temp;
	//vector<float> arr_pres;
	//vector<float> arr_humi;

public:
	float    pressure_pa, pressure, temperature, humidity, humidity_dht;

	MySensor( I2C_HandleTypeDef * hi2c1 );

	bool get_data();

};



#endif /* SRC_MYSENSOR_H_ */
