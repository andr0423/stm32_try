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
	uint32_t prv = HAL_GetTick();
    if ( ( prv - this->time_key_press ) > 300 )
	{
      this->is_pressed = true;
      this->time_key_press = prv;
    }
  }
}


bool MyButton::is_Press(){
	this->catch_click();
	if ( this->is_pressed ){
		this->is_pressed = false;
		return true;
	}
	return false ;
}
