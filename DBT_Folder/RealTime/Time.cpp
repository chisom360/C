
// Member-function definitions for class Time.
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member
Time::Time(int hour, int minute, int second, int day)
{
   setTime(hour, minute, second, day); // validate and set time
} // end Time constructor

// set new Time value using universal time
void Time::setTime(int h, int m, int s, int d)
{
   setHour(h);   // set private field hour
   setMinute(m); // set private field minute
   setSecond(s); // set private field second
   setDay(d);
} // end function setTime

void Time::setDay(int d)
{
   if (d >= 1 && d < 8)
      day = d;
   else

      throw invalid_argument("day must be 1-7");
}
// set hour value
void Time::setHour(int h)
{
   if (h >= 0 && h < 24)
      hour = h;
   else
      throw invalid_argument("hour must be 0-23");
} // end function setHour

// set minute value
void Time::setMinute(int m)
{
   if (m >= 0 && m < 60)
      minute = m;
   else
      throw invalid_argument("minute must be 0-59");
} // end function setMinute

// set second value
void Time::setSecond(int s)
{
   if (s >= 0 && s < 60)
      second = ((s >= 0 && s < 60) ? s : 0);
   else
      throw invalid_argument("second must be 0-59");
} // end function setSecond

// return hour value
int Time::getHour()
{
   return hour;
} // end function getHour

// return minute value
int Time::getMinute()
{
   return minute;
} // end function getMinute

// return second value
int Time::getSecond()
{
   return second;
} // end function getSecond

int Time::getDay()
{
   return day;
}
/*
std::ostream &operator<<(std::ostream &out, Time &t)
{
   return t.printTime(out);
}


ostream &printTime(ostream &out)
{
   auto oldfill = out.fill('0');
   return out << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << setfill('0') << setw(2) << getMinute()
              << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM")
              << std::setfill(oldfill);
}
*/

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard()
{
   cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setfill('0') << setw(2) << getMinute()
        << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
} // end function printStandard
