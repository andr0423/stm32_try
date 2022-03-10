/*
 * MyBlinker.h
 *
 *  Created on: Feb 19, 2022
 *      Author: andrus
 */
#pragma once

#ifndef SRC_MYBLINKER_H_
#define SRC_MYBLINKER_H_

#include "main.h"



class MyBlinker {
	bool red;
	bool blue;
	uint16_t red_pin;
	uint16_t blue_pin;

public:
	MyBlinker();

	void red_on();
	void red_off();
	void red_toggle();

	void blue_on();
	void blue_off();
	void blue_toggle();

	void red_triple();
};



#endif /* SRC_MYBLINKER_H_ */
