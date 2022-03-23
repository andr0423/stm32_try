/*
 * MyButton.h
 *
 *  Created on: Mar 23, 2022
 *      Author: a.demykin
 */

#ifndef SRC_MYBUTTON_H_
#define SRC_MYBUTTON_H_

#include "main.h"



class MyButton {
	uint32_t lastClick;
	bool is_pressed;
	bool is_dbl;
	bool is_long;
public:
	MyButton();
	void catch_click();
	bool is_Press();
	bool is_Dbl();
	bool is_Long();
};

#endif /* SRC_MYBUTTON_H_ */
