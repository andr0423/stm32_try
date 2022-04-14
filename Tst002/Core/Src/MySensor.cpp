/*
 * MySensor.cpp
 *
 *  Created on: 2 mar 2022
 *      Author: andrus
 */

#include <MySensor.h>



MySensor::MySensor(){
	this->init_var();
}

MySensor::MySensor( I2C_HandleTypeDef * dev ) {
	this->init_var();
	this->set_bmp(dev);
}

void MySensor::init_var(){
	this->pressure        = 0;
	this->pressure_pa     = 0;
	this->temperature     = 0;
	this->humidity        = 0;
	this->temperature_dht = 0;
	this->humidity_dht    = 0;
}

void MySensor::set_bmp( I2C_HandleTypeDef * bmp ){
	bmp280_init_default_params( &this->bmp280.params );

	this->bmp280.addr = BMP280_I2C_ADDRESS_0;
	//this->bmp280.addr = BMP280_I2C_ADDRESS_1;

	this->bmp280.i2c = bmp;

	while ( ! bmp280_init( &(this->bmp280), &(this->bmp280).params) ) {
		HAL_Delay(1000);
	}
	this->bme280p = this->bmp280.id == BME280_CHIP_ID;
}

void MySensor::set_dht( DHT_sensor * dht ){
	this->use_dht = true;
	this->dht = dht;
}

bool MySensor::get_data(){

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

	// 1 Pa == 100 / 0.75 mm Hg
	this->pressure = this->pressure_pa * 0.75 / 100;


	if(this->use_dht){
		DHT_data d = DHT_getData( this->dht );
		this->humidity_dht = d.hum;
		this->temperature_dht = d.temp;
	}

	return true;
}
