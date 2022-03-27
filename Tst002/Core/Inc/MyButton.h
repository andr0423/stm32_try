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

	uint8_t flag_key_press = 1;
	uint32_t time_key_press = 0;

	uint8_t flag_key_release = 0;
	uint32_t time_key_release = 0;

	bool is_pressed = false;
	bool is_released = false;
	//bool is_dbl;
	//bool is_long;

public:
	MyButton( GPIO_TypeDef * port, uint16_t pin );
	void catch_click();
	bool is_Press();
	bool is_Dbl();
	bool is_Long();
};

#endif /* SRC_MYBUTTON_H_ */
