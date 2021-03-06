/*
 * MyOled.cpp
 *
 *  Created on: Mar 8, 2022
 *      Author: andrus
 */

#include "MyOled.h"

MyOled::MyOled() {
}

void MyOled::init() {
  ssd1306_Init();
  ssd1306_Fill(white);
  ssd1306_UpdateScreen();

  HAL_Delay(500);
  ssd1306_Fill(black);
  ssd1306_UpdateScreen();
  HAL_Delay(500);
}

void MyOled::hello() {
  this->clear();
  this->write_str(18, 12, "Hello!", &Font_16x26);
  ssd1306_DrawRectangle(0, 0, 127, 47, white);
  ssd1306_DrawRectangle(0, 48, 127, 63, white);
  this->update();
  for (int i = 1; i < 127; i++) {
    ssd1306_Line(i, 49, i, 62, white);
    HAL_Delay(3);
    this->update();
  }
  HAL_Delay(1000);
}

int MyOled::get_display() {
  return this->current_display;
}

void MyOled::set_display(int display) {
  this->current_display = display % 4;
  this->display();
}

void MyOled::next_display() {
  this->current_display = (this->current_display + 1) % 4;
  this->display();
}

void MyOled::prev_display() {
  if (this->current_display > 0) {
    this->current_display = this->current_display - 1;
  } else {
    this->current_display = 3;
  }
  this->display();
}

void MyOled::display() {
  if (this->testing) {
    return;
  }
  this->clear();
  switch (this->current_display) {
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

void MyOled::display_tph() {
  this->write_str(2, 2, "Temp: % 3.2f C", this->tmpr);
  this->write_str(2, 18, "Pres:% 4.2f mm Hg", this->prss);
  this->write_str(2, 34, "Humd: % 3.2f %%", this->hmdt);
  ssd1306_Line(0, 48, 127, 48, white);
  this->write_str(4, 52, "VKR c++ DEMYKIN 2022", &Font_6x8);
  ssd1306_Line(0, 63, 127, 63, white);
}

void MyOled::display_graph() {
  ssd1306_Line(0, 15, 127, 15, white);
  ssd1306_Line(0, 31, 127, 31, white);
  ssd1306_Line(0, 47, 127, 47, white);
  sprintf(this->buffer, "%2.2f  %3.2f  %2.2f", this->tmpr, this->prss, this->hmdt);
  this->write_str(2, 52, this->buffer, &Font_6x8);

  //this->paint_chart(0, 128, this->t.m_point, 4);
  //this->paint_chart(1, 128, this->p.m_point, 4);
  //this->paint_chart(2, 128, this->h.m_point, 4);

  //this->paint_chart_dot(0, 128, this->t.m_point, 2);
  //this->paint_chart_dot(1, 128, this->p.m_point, 2);
  //this->paint_chart_dot(2, 128, this->h.m_point, 2);

  this->paint_chart(0, 128, this->t.getMPoint());
  this->paint_chart(1, 128, this->p.getMPoint());
  this->paint_chart(2, 128, this->h.getMPoint());
}

void MyOled::paint_chart( int row, int size, const int * points, int stretch ) {
    int offset = 16 * row;
    int x1 = 0;
    int y1 = 15 - points[0] + offset;
    int x2, y2;
    for ( int x = stretch ; x < size ; x = x + stretch ){
        x2 = x;
        y2 = ( 15 - points[x] + offset );
        ssd1306_Line( x1, y1, x2, y2, white);
        x1 = x2;
        y1 = y2;
    }

}

void MyOled::paint_chart_dot( int row, int size, const int * points, int stretch ) {
    for ( int x = 0 ; x < size ; x = x + stretch ){
        ssd1306_DrawPixel( x*2, ( 15 - points[x] + 16 * row ), white );
    }
}

void MyOled::display_conf() {
  this->font = &Font_6x8;
  this->write_str(2, 2, "IoT device:");
  sprintf(this->buffer, "    %03d.%03d.%03d.%03d", IP_ADDRESS[0], IP_ADDRESS[1],
      IP_ADDRESS[2], IP_ADDRESS[3]);
  this->write_str(2, 14, this->buffer);
  this->write_str(2, 26, "mqtt-bocker:");
  sprintf(this->buffer, "    %s", mqtt_server);
  this->write_str(2, 38, this->buffer);
  this->font = &Font_7x10;
  this->write_str(2, 50, "CLICK to next");
}

void MyOled::display_test() {
  this->write_str(31, 18, "Test", &Font_16x26);
}

void MyOled::oled_testing() {
  this->testing = true;
  this->clear();
  ssd1306_TestAll();
  this->display();
  this->testing = false;
  this->clear();
}

void MyOled::clear() {
  ssd1306_Fill(black);
}

void MyOled::update() {
  ssd1306_UpdateScreen();
}

void MyOled::set_tph(float tmpr, float prss, float hmdt) {
  this->tmpr = tmpr;
  this->prss = prss;
  this->hmdt = hmdt;
  t.add(tmpr);
  p.add(prss);
  h.add(hmdt);
}

void MyOled::write_str(uint8_t x, uint8_t y, const char *const_str) {
  ssd1306_SetCursor(x, y);
  char *str = const_cast<char*>(const_str);
  this->ch = ssd1306_WriteString(str, *this->font, white);
}

void MyOled::write_str(uint8_t x, uint8_t y, const char *const_str, FontDef * with_font) {
    FontDef * fnt = this->font;
    this->font = with_font;
    this->write_str(x, y, const_str);
    this->font = fnt;
}

void MyOled::write_str(uint8_t x, uint8_t y, const char *const_str, float val) {
  sprintf(this->buffer, const_str, val);
  this->write_str(x, y, this->buffer);
}


