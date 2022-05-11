/*
 * MyButton.cpp
 *
 *  Created on: Mar 23, 2022
 *      Author: a.demykin
 */

#include "MyButton.h"

MyButton::MyButton( GPIO_TypeDef * port, uint16_t pin ) : port(port), pin(pin) {}

void MyButton::catch_click(){

  if( HAL_GPIO_ReadPin(this->port, this->pin) == GPIO_PIN_SET )
  {
	uint32_t prt = HAL_GetTick();
	if (
		( prt - this->time_key_press ) > this->rattling_timoute_press
	)
	{
		this->clean();
		this->time_key_press = prt;
		this->is_pressed = true;
	}
  }
  else if( HAL_GPIO_ReadPin(this->port, this->pin) == GPIO_PIN_RESET )
  {
	uint32_t rlt = HAL_GetTick();
    if (
    	( rlt - this->time_key_press ) > this->rattling_timoute_release
	)
	{
    	this->time_key_release = rlt;
    	this->is_pressed = false;
    	this->is_released = true;
    	this->is_clicked = true;
    }

    if ( this->is_clicked )
    {
        uint32_t press_interval = this->time_key_release - this->time_key_press;
    	if (press_interval > this->long_timeout)
    	{
    		this->is_short = false;
    		this->is_middle = false;
    		this->is_long = true;
    	}
    	else if (press_interval > this->middle_timeout)
    	{
    		this->is_short = false;
    		this->is_middle = true;
    		this->is_long = false;
    	}
    	else{
    		this->is_short = true;
    		this->is_middle = false;
    		this->is_long = false;
    	}
    }
  }
}


bool MyButton::is_Click(){
	return this->is_clicked;
}

bool MyButton::is_Short(){
  return this->is_short;
}

bool MyButton::is_Middle(){
    return this->is_middle;
}

bool MyButton::is_Long(){
    return this->is_long;
}


void MyButton::clean(){

	this->is_pressed = false;
	this->is_released = false;

	this->is_clicked = false;
	this->is_long = false;
	this->is_short = false;
 // bool is_dbl = false;

}

