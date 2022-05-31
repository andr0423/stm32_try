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
	GPIO_TypeDef * port;
	uint16_t pin;

	uint32_t rattling_timoute_press = 100;
	uint32_t rattling_timoute_release = 10;
	uint32_t middle_timeout = 1000;
	uint32_t long_timeout = 3000;

	uint32_t time_key_press = 0;
	uint32_t time_key_release = 0;

	bool is_pressed = false;
	bool is_released = false;
	bool is_clicked = false;

	bool is_short = false;
	bool is_middle = false;
	bool is_long = false;

public:
	MyButton( GPIO_TypeDef * port, uint16_t pin );
	void catch_click();
	void clean();
	bool is_Click();
	bool is_Short();
	bool is_Middle();
	bool is_Long();
};

#endif /* SRC_MYBUTTON_H_ */
