// curTime.cpp 
// Defines the global function currentTime()
// ---------------------------------------------------

#include "DayTime.h"
#include <ctime>    // Standard functions time(), localtime()
using namespace std;

const DayTime& currentTime()      // Returns the current time.
{                                
  static DayTime curTime;
  time_t sec;  time(&sec);        // Gets the current time

  struct tm *zeit = localtime(&sec);  // Initialize the struct tm.

  curTime.setTime( zeit->tm_hour, zeit->tm_min, zeit->tm_sec );

  return curTime;
}
