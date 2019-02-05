
// RealTime class uses RTOS_Handler and Time class to set the data member in Time Class.
// Member functions defined in Time.cpp.

// prevent multiple inclusions of header
#ifndef REALTIME_H
#define REALTIME_H
//#include "../Time/Time.h"
#include "Time.h"

// RealTime abstract data type definition
class RealTime
{
public:
  Time t; //Time class object
  RealTime();
  int getRealTimeHour();
  int getRealTimeMinutes();
  int getRealTimeSeconds();
  int getRealDay();

  //functions to implement
  //int Timer();
  //setRealTime(int, int);
}; // end class Time

#endif
