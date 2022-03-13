/*
 * MyOled.cpp
 *
 *  Created on: Mar 8, 2022
 *      Author: andrus
 */

#include "MyOled.h"



MyOled::MyOled() {}

void MyOled::init() {
    ssd1306_Init();
    ssd1306_Fill(SSD1306_COLOR::White);
    ssd1306_UpdateScreen();

        HAL_Delay(500);
    ssd1306_Fill(SSD1306_COLOR::Black);
    ssd1306_UpdateScreen();
    HAL_Delay(500);
}

void MyOled::hello() {
	this->clear();
	this->font = &Font_16x26;
	this->write_str( 18, 12, "Hello!" );
	this->font = &Font_7x10;
	ssd1306_DrawRectangle( 0,  0, 127, 47, SSD1306_COLOR::White );
	ssd1306_DrawRectangle( 0, 48, 127, 63, SSD1306_COLOR::White );
	this->update();
	for ( int i = 1 ; i < 127 ; i++ ){
		ssd1306_Line( i, 49, i, 62, SSD1306_COLOR::White );
		HAL_Delay(8);
		this->update();
	}
    HAL_Delay(1000);
}

void MyOled::display_tph(float tmpr, float prss, float hmdt){
	this->clear();
	this->write_str( 2,  2, "Temp: % 3.2f C", tmpr );
	this->write_str( 2, 18, "Pres: %4.2f mm Hg", prss );
	this->write_str( 2, 34, "Humd:  % 2.2f %%", hmdt );

	ssd1306_Line( 0, 48, 127, 48, SSD1306_COLOR::White );
	this->font = &Font_6x8;
	this->write_str( 4, 52, "VKR c++ DEMYKIN 2022" );
	this->font = &Font_7x10;
	ssd1306_Line( 0, 63, 127, 63, SSD1306_COLOR::White );
	this->update();
}

void MyOled::display_test() {
	  ssd1306_TestAll();
}

void MyOled::clear(){
	ssd1306_Fill(SSD1306_COLOR::Black);
}

void MyOled::update(){
	ssd1306_UpdateScreen();
}

void MyOled::write_str(uint8_t x, uint8_t y, const char * const_str){
	  ssd1306_SetCursor(x, y);
	  char * str = const_cast<char*>(const_str);
	  this->ch = ssd1306_WriteString( str, *this->font, SSD1306_COLOR::White );
}

void MyOled::write_str(uint8_t x, uint8_t y, const char * const_str, float val){
	  sprintf ( this->buffer, const_str, val );
	  this->write_str( x, y, this->buffer );
}
