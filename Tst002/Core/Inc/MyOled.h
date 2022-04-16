/*
 * MyOled.h
 *
 *  Created on: Mar 8, 2022
 *      Author: andrus
 */

#ifndef SRC_MYOLED_H_
#define SRC_MYOLED_H_

#include "ssd1306.h"
#include "ssd1306_tests.h"
#include <string>



class MyOled {
	FontDef * font = &Font_7x10;
	char buffer [64];
	char ch;
	int current_display = 0;
	float tmpr;
	float prss;
	float hmdt;
	bool testing = false;

	//void clear_buffer();

public:
	MyOled();
	void init();
	void hello();

	void next_display();

	void display();

	void set_tph(float, float, float);
	void display_tph();

	void display_graph();

	void display_conf();

	void display_test();
	void oled_testing();

	void clear();
	void update();
	void write_str( uint8_t, uint8_t, const char * );
	void write_str( uint8_t, uint8_t, const char *, float );
	void write_str( uint8_t, uint8_t, const char *, float, float, float);
};



#endif /* SRC_MYOLED_H_ */
