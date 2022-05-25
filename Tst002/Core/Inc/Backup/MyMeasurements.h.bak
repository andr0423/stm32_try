/*
 * MyMeasurements.h
 *
 *  Created on: 27 mar 2022
 *      Author: andrus
 */

#ifndef SRC_MYMEASUREMENTS_H_
#define SRC_MYMEASUREMENTS_H_

#include "main.h"
#include <deque>



class MyMeasurements {
	int depth = 128;
	std::deque <float> temperature;
	std::deque <float> pressure;
	std::deque <float> humidity;

public:
	MyMeasurements();
	virtual ~MyMeasurements();
	void set(float, float, float);

};

#endif /* SRC_MYMEASUREMENTS_H_ */
