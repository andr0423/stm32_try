/*
 * MyChart.cpp
 *
 *  Created on: 20 jun 2022
 *      Author: andrus
 */

#include "MyChart.h"

MyChart::MyChart() {}

void MyChart::add( float val ) {

    if ( this->m_full_size ){
        this->m_last = this->m_first;
        this->m_first = ( this->m_first + 1 ) % this->m_capacity ;
    }else{
        this->m_last = this->m_size;
        this->m_size +=1;
        if ( this->m_size == this->m_capacity ){
            this->m_full_size = true;
        }
    }

    this->m_mes[this->m_last] = val;

    this->chart_recalculate();
}

void MyChart::chart_recalculate() {
    int min = 0;
    int max = 0;
    for ( int i = 0; i < this->m_size; i++ ){
      if ( m_mes[i] < m_mes[min] ){
        min = i;
      }
      if ( m_mes[i] > m_mes[max] ){
        max = i;
      }
    }

    float diff = this->m_mes[max] - this->m_mes[min];
    float mid = diff / 2.0 + this->m_mes[min];
    float coast = diff / 15.0 ;

    int mp = this->m_first;
    for ( int i = 0 ; i < this->m_size ; i++ ){
        if ( coast > 0 ) {
          this->m_point[i] = ( this->m_mes[mp] - mid ) / coast + 8.0;
          if ( this->m_point[i] == 0 ){
              this->m_point[i] = 1;
          }
      }else{
          this->m_point[i] = 8;
      }
      mp = ( mp + 1 ) % this->m_capacity;
    }
}

