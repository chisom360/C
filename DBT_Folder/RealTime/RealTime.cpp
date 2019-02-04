
// Member-function definitions for class RealTime.
#include <ctime>
#include "RealTime.h" // include definition of class RealTime from RealTime.h
using namespace std;
#include <time.h>

// return hour value
int RealTime::setRealHour()
{
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    int tempHour = timePtr->tm_hour;
    return tempHour;

} // end function getHour

/*int RealTime::getRealMinute()
{
    return minute;
} // end function getMinute

// return second value
int RealTime::getRealSecond()
{
    return second;
} // end function getSecond*/

//struct *ReaTime::GetTimeStruct()
//{
//time_t rawtime;
// struct tm *timeinfo;

//time(&rawtime);
//timeinfo = localtime(&rawtime);
//return timeinfo;
//}