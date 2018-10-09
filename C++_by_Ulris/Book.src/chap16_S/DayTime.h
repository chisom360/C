// ----------------------------------------------------
// DayTime.h
// The class DayTime represents the time in hours, 
// minutes and seconds.
// ----------------------------------------------------
#ifndef _DAYTIME_
#define _DAYTIME_

#include <iostream>
#include <iomanip>
using namespace std;
 
class DayTime
{
  private:
    short hour, minute, second;
    bool overflow;

  public:
    DayTime( int h = 0, int m = 0, int s = 0)
    { 
      overflow = false;
      if( !setTime( h, m, s))         // this->setTime(...)
        hour = minute = second = 0; 
    }
    bool setTime(int hour, int minute, int second = 0)
    {
      if(    hour   >= 0  &&  hour < 24 
          && minute >= 0  &&  minute < 60
          && second >= 0  &&  second < 60 ) 
      {
        this->hour   = (short)hour; 
        this->minute = (short)minute; 
        this->second = (short)second; 
        return true;
      }
      else
        return false;
    }


    int getHour()   const { return hour;   }
    int getMinute() const { return minute; };
    int getSecond() const { return second; };

    int asSeconds() const      // Daytime in seconds
    {
      return (60*60*hour + 60*minute + second);
    } 
 
    bool isLess( DayTime t) const  // Compares
                                   // *this and t.
    {
      return  asSeconds() < t.asSeconds();
    }      // this->sSeconds() < t.asSeconds(); 
     
    void print() const
    {
      cout << setfill('0')
           << setw(2) << hour    << ':'
           << setw(2) << minute  << ':'
           << setw(2) << second  << " o'clock" << endl;
      cout << setfill(' ');
    }
    void swap( DayTime& t)       // Just one parameter!
    {                            // Swaps *this and t:
      DayTime temp(t);  t = *this;  *this = temp;
    }
};

#endif   // _DAYTIME_
