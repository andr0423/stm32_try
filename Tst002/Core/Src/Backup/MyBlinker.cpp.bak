/*
 * MyBlinker.cpp
 *
 *  Created on: Feb 19, 2022
 *      Author: andrus
 */

#include <MyBlinker.h>



MyBlinker::MyBlinker() {
	this->red       = false;
	this->blue      = false;
	this->blue_pin  = LD2_Pin;
	this->red_pin   = LD3_Pin;

}

void MyBlinker::red_on(){
	red = true;
	HAL_GPIO_WritePin(GPIOB, red_pin, GPIO_PIN_SET);
}

void MyBlinker::red_off(){
	red = false;
	HAL_GPIO_WritePin(GPIOB, red_pin, GPIO_PIN_RESET);
}

void MyBlinker::red_toggle(){
	if( this->red ){
		this->red_off();
	}else{
		this->red_on();
	}
}

void MyBlinker::blue_on(){
	blue = true;
	HAL_GPIO_WritePin(GPIOB, blue_pin, GPIO_PIN_SET);
}

void MyBlinker::blue_off(){
	blue = false;
	HAL_GPIO_WritePin(GPIOB, blue_pin, GPIO_PIN_RESET);
}

void MyBlinker::blue_toggle(){
	if( this->blue ){
		this->blue_off();
	}else{
		this->blue_on();
	}
}

void MyBlinker::red_triple(){
	this->red_toggle();  //1
	HAL_Delay(200);
	this->red_toggle();
	HAL_Delay(200);
	this->red_toggle();  //2
	HAL_Delay(200);
	this->red_toggle();
	HAL_Delay(200);
	this->red_toggle();  //3
	HAL_Delay(200);
	this->red_toggle();
}
