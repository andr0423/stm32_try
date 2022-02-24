/*
 * MyBlinker.cpp
 *
 *  Created on: Feb 19, 2022
 *      Author: andrus
 */

#include "MyBlinker.h"



MyBlinker::MyBlinker() {
	this->red       = false;
	this->green     = false;
	this->blue      = false;
	this->red_pin   = LD3_Pin;
	this->green_pin = LD1_Pin;
	this->blue_pin  = LD2_Pin;
}

// MyBlinker::~MyBlinker() {}

void MyBlinker::red_on(){
	red = true;
	HAL_GPIO_WritePin(GPIOB, red_pin, GPIO_PIN_SET);
}

void MyBlinker::red_off(){
	red = false;
	HAL_GPIO_WritePin(GPIOB, red_pin, GPIO_PIN_RESET);
}

void MyBlinker::green_on(){
	red = true;
	HAL_GPIO_WritePin(GPIOB, green_pin, GPIO_PIN_SET);
}

void MyBlinker::green_off(){
	red = false;
	HAL_GPIO_WritePin(GPIOB, green_pin, GPIO_PIN_RESET);
}

void MyBlinker::blue_on(){
	blue = true;
	HAL_GPIO_WritePin(GPIOB, blue_pin, GPIO_PIN_SET);
}

void MyBlinker::blue_off(){
	blue = false;
	HAL_GPIO_WritePin(GPIOB, blue_pin, GPIO_PIN_RESET);
}
