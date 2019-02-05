
// Time class containing a constructor with default arguments.
// Member functions defined in Time.cpp.

// prevent multiple inclusions of header
#ifndef TIME_H
#define TIME_H
#include <iostream>

// Time abstract data type definition
class Time
{
public:
  Time(int = 0, int = 0, int = 0, int = 1); // default constructor

  // set functions
  void setTime(int, int, int, int); // set hour, minute, second
  void setHour(int);                // set hour (after validation)
  void setMinute(int);              // set minute (after validation)
  void setSecond(int);              // set second (after validation)
  void setDay(int);
  //friend std::ostream &operator<<(std::ostream &out, const Time &t);
  //std::ostream &printTime(std::ostream &out) const;
  // get functions
  int getHour();   // return hour
  int getMinute(); // return minute
  int getSecond(); // return second
  int getDay();

  void printStandard(); // output time in standard-time format
private:
  int hour;   // 0 - 23 (24-hour clock format)
  int minute; // 0 - 59
  int second; // 0 - 59
  int day;    // 1 - 7
};            // end class Time

#endif
