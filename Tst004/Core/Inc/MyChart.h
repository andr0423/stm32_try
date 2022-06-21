/*
 * MyMeasurements.h
 *
 *  Created on: 27 mar 2022
 *      Author: andrus
 */

#ifndef SRC_MYMEASUREMENTS_H_
#define SRC_MYMEASUREMENTS_H_

#include "main.h"

//
// chart height 15 px
// chart width 128 px


class MyChart {
  int m_size = 128;
  float m_mes[128] = {};

  int m_first = 0;
  int m_last = 0;
  int m_fill = 0;

  void chart_recalculate();

public:

  int m_point[128] = {};

  MyChart();
  void add(float);

};

#endif /* SRC_MYMEASUREMENTS_H_ */

