/*
 * MyButton.h
 *
 *  Created on: Mar 23, 2022
 *      Author: a.demykin
 */

#ifndef SRC_MYBUTTON_H_
#define SRC_MYBUTTON_H_

#include "main.h"

class MyButton {
  GPIO_TypeDef *port;
  uint16_t pin;

  const uint32_t rattling_timoute_press = 100;
  const uint32_t rattling_timoute_release = 10;
  const uint32_t middle_timeout = 1000;
  const uint32_t long_timeout = 3000;

  uint32_t time_key_press = 0;
  //uint32_t time_key_release = 0;  // --> is overkill?

  //bool is_pressed = false;   // --> is overkill too?
  //bool is_released = false;  // --> is overkill too?
  //bool is_clicked = false;   // --> is overkill too?

  bool is_short = false;
  bool is_middle = false;
  bool is_long = false;

  void clean();

public:
  MyButton(GPIO_TypeDef *port, uint16_t pin);
  //void catch_click();        // --> is overkill too?
  //bool is_Click();           // --> is overkill too?
  bool catch_click();
  bool is_Short();
  bool is_Middle();
  bool is_Long();
};

#endif /* SRC_MYBUTTON_H_ */

