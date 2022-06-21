/*
 * MyMeasurements.cpp
 *
 *  Created on: 27 mar. 2022
 *      Author: andrus
 */

#include "MyChart.h"

MyChart::MyChart() {}


void MyChart::add(float val) {

  if ( this->m_fill < this->m_size ){
	  this->m_fill += 1;
  }else{
    m_first = this->m_last;
  }

  this->m_mes[this->m_last] = val;

  this->m_last = ( this->m_last + 1 ) % this->m_size ;

  this->chart_recalculate();
}

void MyChart::chart_recalculate() {
    int min = 0;
    int max = 0;
    for ( int i = 0; i < this->m_fill; i++ ){
      if (m_mes[i] < m_mes[min]){
        min = i;
      }
      if (m_mes[i] > m_mes[max]){
        max = i;
      }
    }

    float mid = ( this->m_mes[max] - this->m_mes[min] ) / 2 + this->m_mes[min];
    float coast = ( this->m_mes[max] - this->m_mes[min] ) / 15 ;

    int mp = this->m_first;
    for ( int i = 0 ; i < this->m_fill ; i++ ){
      if ( coast > 0 ) {
          this->m_point[i] = ( this->m_mes[mp] - mid ) / coast + 8.0;
          if (this->m_point[i] == 0 ){
        	  this->m_point[i] = 1;
          }
      }else{
    	  this->m_point[i] = 8;
      }
      mp = ( mp + 1 ) % this->m_size;
    }
}



