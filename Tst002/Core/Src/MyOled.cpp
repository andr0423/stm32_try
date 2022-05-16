/*
 * MyOled.cpp
 *
 *  Created on: Mar 8, 2022
 *      Author: andrus
 */

#include "MyOled.h"



MyOled::MyOled() {}

//void MyOled::clear_buffer(){
//	for (int i = 0; i < 64; i++){
//		this->buffer[i] = 0;
//	}
//}


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
		HAL_Delay(3);
		this->update();
	}
    HAL_Delay(1000);
}

int MyOled::get_display(){
	return this->current_display;
}

void MyOled::set_display( int display ){
	this->current_display = display % 4 ;
	this->display();
}

void MyOled::next_display(){
	this->current_display = ( this->current_display + 1 ) % 4 ;
	this->display();
}

void MyOled::prev_display(){
	if ( this->current_display > 0) {
		this->current_display = this->current_display - 1;
	}
	else{
		this->current_display = 3;
	}
	this->display();
}

void MyOled::display(){
	if (this->testing){
		return;
	}
	this->clear();
	switch(this->current_display)
	{
	case 0:
		this->display_tph();
		break;
	case 1:
		this->display_graph();
		break;
	case 2:
		this->display_conf();
		break;
	case 3:
		this->display_test();
		break;
	}
	this->update();
}

void MyOled::set_tph(float tmpr, float prss, float hmdt){
	this->tmpr = tmpr;
	this->prss = prss;
	this->hmdt = hmdt;
}

void MyOled::display_tph(){
	this->write_str( 2,  2, "Temp: % 3.2f C", this->tmpr );
	this->write_str( 2, 18, "Pres:% 4.2f mm Hg", this->prss );
	this->write_str( 2, 34, "Humd: % 3.2f %%", this->hmdt );

	ssd1306_Line( 0, 48, 127, 48, SSD1306_COLOR::White );
	this->font = &Font_6x8;
	this->write_str( 4, 52, "VKR c++ DEMYKIN 2022" );
	this->font = &Font_7x10;
	ssd1306_Line( 0, 63, 127, 63, SSD1306_COLOR::White );
}

void MyOled::display_graph(){
	//this->clear();
	ssd1306_Line( 0, 15, 127, 15, SSD1306_COLOR::White );
	ssd1306_Line( 0, 31, 127, 31, SSD1306_COLOR::White );
	ssd1306_Line( 0, 47, 127, 47, SSD1306_COLOR::White );
	this->font = &Font_6x8;
	//this->write_str( 2, 50, "CLICK to next");
	this->write_str( 2, 52, "%2.2f  %3.2f  %2.2f", this->tmpr, this->prss, this->hmdt );
	this->font = &Font_7x10;
}

void MyOled::display_conf(){
	this->font = &Font_6x8;
	this->write_str( 2,  2, "IoT device:");
	this->write_str( 2, 14, "    192.168.100.200");
	this->write_str( 2, 26, "mqtt-bocker:");
	this->write_str( 2, 38, "    192.168.100.100");
	this->font = &Font_7x10;
	this->write_str( 2, 50, "CLICK to next");
}

void MyOled::display_test() {
    this->font = &Font_16x26;
    this->write_str( 31, 18, "Test" );
    this->font = &Font_7x10;
}

void MyOled::oled_testing() {
	this->testing = true;
	this->clear();
    // ssd1306_TestAll();
    ssd1306_Init();
    ssd1306_TestRectangle();
    this->display();
    this->testing = false;
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

void MyOled::write_str(uint8_t x, uint8_t y, const char * const_str, float v1, float v2, float v3){
    sprintf ( this->buffer, const_str, v1, v2, v3 );
    this->write_str( x, y, this->buffer );
}

