/*
 * MyOled.h
 *
 *  Created on: Mar 8, 2022
 *      Author: andrus
 */

#ifndef SRC_MYOLED_H_
#define SRC_MYOLED_H_

#include <string>
#include "ssd1306.h"
#include "ssd1306_tests.h"
#include "MyChart.h"

extern const char mqtt_server[15];
extern uint8_t IP_ADDRESS[4];

class MyOled {
  FontDef *font = &Font_7x10;

  SSD1306_COLOR white = SSD1306_COLOR::White;
  SSD1306_COLOR black = SSD1306_COLOR::Black;

  char buffer[64];
  char ch;
  int current_display = 0;
  float tmpr;
  float prss;
  float hmdt;
  bool testing = false;

  MyChart t = MyChart();
  MyChart p = MyChart();
  MyChart h = MyChart();

  void clear();
  void update();
  void write_str(uint8_t, uint8_t, const char*);
  void write_str(uint8_t, uint8_t, const char*, FontDef *);
  void write_str(uint8_t, uint8_t, const char*, float);
  void paint_chart( int, int, int *, int = 1 );
  void paint_chart_dot( int, int, int *, int = 1 );

  void set_display(int);
  void display_tph();
  void display_graph();
  void display_conf();
  void display_test();

public:
  MyOled();
  void init();
  void hello();
  int get_display();
  void next_display();
  void prev_display();
  void oled_testing();

  void display();
  void set_tph(float, float, float);


};

#endif /* SRC_MYOLED_H_ */

