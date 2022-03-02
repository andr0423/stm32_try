/*
 * MySensor.cpp
 *
 *  Created on: 2 mar. 2022 г.
 *      Author: andrus
 */

#include <MySensor.h>



MySensor::MySensor( I2C_HandleTypeDef * dev ) {

	this->pressure    = 0;
	this->pressure_pa = 0;
	this->temperature = 0;
	this->humidity    = 0;

	bmp280_init_default_params( &this->bmp280.params );

	this->bmp280.addr = BMP280_I2C_ADDRESS_0;
	//this->bmp280.addr = BMP280_I2C_ADDRESS_1;

	this->bmp280.i2c = dev;

	while ( ! bmp280_init( &(this->bmp280), &(this->bmp280).params) ) {
		HAL_Delay(1000);
	}
	this->bme280p = this->bmp280.id == BME280_CHIP_ID;

}

bool MySensor::read_data(){

	while (
			! bmp280_read_float(
					&this->bmp280,
					&this->temperature,
					&this->pressure_pa,
					NULL
					)
			) {

		HAL_Delay(500);
	}

	this->pressure = this->pressure_pa * 0.75 / 100; // *100 / 0.75 mm.rt.st

	return true;
}
