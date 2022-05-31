/*
 * MyBlinker.h
 *
 *  Created on: Feb 19, 2022
 *      Author: andrus
 */

#ifndef SRC_MYBLINKER_H_
#define SRC_MYBLINKER_H_

#include "main.h"

class MyBlinker {
  bool is_on = false;
  uint16_t led_pin;

public:
  MyBlinker(uint16_t pin);
  void on();
  void off();
  void toggle();
};

#endif /* SRC_MYBLINKER_H_ */

