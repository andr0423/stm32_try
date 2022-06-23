/*
 * MyChart.h
 *
 *  Created on: 20 jun 2022
 *      Author: andrus
 */

#ifndef SRC_MYMEASUREMENTS_H_
#define SRC_MYMEASUREMENTS_H_

#include "main.h"

// chart height 15 px
// chart width 128 px

class MyChart {
    int m_capacity = 128;
    float m_mes[128] = {};
    int m_point[128] = {};

    int m_first = 0;
    int m_last = 0;
    int m_size = 0;
    bool m_full_size = false;

    void chart_recalculate();
public:
    MyChart();
    void add(float);

    const int* getMPoint() const {
        return m_point;
    }

};

#endif /* SRC_MYMEASUREMENTS_H_ */

