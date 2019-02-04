
// Member-function definitions for class RealTime.
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "RealTime.h" // include definition of class RealTime from RealTime.h
using namespace std;
#include <time.h>

// RealTime constructor initializes each data member
RealTime::RealTime()
{
    // validate and set time
} // end RealTime constructor

// return hour value
int RealTime::setRealHour()
{
    time_t rawtime;
    struct tm *timeinfo;
    /* get current timeinfo and modify it to the user's choice */
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    //return timeinfo;
    //hour = GetTimeStruct()->tm_hour;
    return timeinfo->tm_hour;

} // end function getHour

// return minute value
/*int RealTime::getRealMinute()
{
    return minute;
} // end function getMinute

// return second value
int RealTime::getRealSecond()
{
    return second;
} // end function getSecond*/

/*struct *ReaTime::GetTimeStruct()
{
    time_t rawtime;
    struct tm *timeinfo;
    /* get current timeinfo and modify it to the user's choice */
//time(&rawtime);
//timeinfo = localtime(&rawtime);
//return timeinfo;
//}