
// Time class containing a constructor with default arguments.
// Member functions defined in Time.cpp.

// prevent multiple inclusions of header
#ifndef REALTIME_H
#define REALTIME_H
#include <iostream>
//#include "/home/bigshow360/Documents/C++/DBT_Folder/Time/Time.h"

// Time abstract data type definition
class RealTime
{
public:
  // RealTime(); // default constructor

  int setRealHour(); // return hour
  /*int getRealMinute(); // return minute
    int getRealSecond(); // return second*/

  //struct *GetTimeStruct();
  void printStandard(); // output time in standard-time format
private:
  //  Time TimeSetter;
  int mHour;   // 0 - 23 (24-hour clock format)
  int mMinute; // 0 - 59
  int mSecond; // 0 - 59
};             // end class Time

#endif
