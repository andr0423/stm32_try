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
	bool green;
	bool blue;
	uint16_t red_pin;
	uint16_t green_pin;
	uint16_t blue_pin;

public:
	MyBlinker();
	//virtual ~MyBlinker();

	void red_on();
	void red_off();
	void green_on();
	void green_off();
	void blue_on();
	void blue_off();

};



#endif /* SRC_MYBLINKER_H_ */
