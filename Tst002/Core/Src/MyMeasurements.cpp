/*
 * MyMeasurements.cpp
 *
 *  Created on: 27 mar. 2022
 *      Author: andrus
 */

#include "MyMeasurements.h"

MyMeasurements::MyMeasurements() {
	this->temperature.resize(this->depth);
	this->pressure.resize(this->depth);
	this->humidity.resize(this->depth);
}

MyMeasurements::~MyMeasurements() {}

void MyMeasurements::set(float temp, float pres, float humi){
	if ( this->temperature.size() == 128 ){
		this->temperature.pop_back();
		this->pressure.pop_back();
		this->humidity.pop_back();
	}
	this->temperature.push_front(temp);
	this->pressure.push_front(pres);
	this->humidity.push_front(humi);


}


