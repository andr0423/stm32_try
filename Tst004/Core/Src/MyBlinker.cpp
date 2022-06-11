/*
 * MyBlinker.cpp
 *
 *  Created on: Feb 19, 2022
 *      Author: andrus
 */

#include <MyBlinker.h>

MyBlinker::MyBlinker(uint16_t pin) :
    led_pin(pin) {
  this->off();
}

void MyBlinker::on() {
  is_on = true;
  HAL_GPIO_WritePin( GPIOB, this->led_pin, GPIO_PIN_SET);
}

void MyBlinker::off() {
  is_on = false;
  HAL_GPIO_WritePin( GPIOB, this->led_pin, GPIO_PIN_RESET);
}

void MyBlinker::toggle() {
  if (this->is_on) {
    this->off();
  } else {
    this->on();
  }
}

