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
  bool bme280p;  // "BME280" or "BMP280"
  bool use_dht = false;
  DHT_sensor *dht;
  void init_var();

public:
  float pressure_pa;
  float pressure;
  float temperature;
  float humidity;
  float temperature_dht;
  float humidity_dht;
  MySensor();
  void set_bmp(I2C_HandleTypeDef*);
  void set_dht(DHT_sensor*);
  void get_data();
};

#endif /* SRC_MYSENSOR_H_ */

