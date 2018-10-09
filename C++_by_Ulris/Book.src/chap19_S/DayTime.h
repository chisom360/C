// ----------------------------------------------------
// DayTime.h
// Class DayTime with all relational operators,
// the operators ++ and -- (Prefix and Postfix),
// such as the operators << and >> for input/output.
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
    bool overflow, underflow;

    void inc()             // private function for ++
    {
      ++second;
      if( second >= 60)    // handle overflow. 
          second = 0,  ++minute;
      if( minute >= 60)
          minute = 0,  ++hour;
      if( hour >= 24)
          hour = 0,  overflow = true;
    }

    void dec()             // private function for --
    {
      --second;
      if( second < 0)      // handle underflow. 
          second = 59,  --minute;
      if( minute < 0)
          minute = 59,  --hour;
      if( hour < 0)
          hour = 0,  underflow = true;
    }

  public:
    DayTime( int h = 0, int m = 0, int s = 0)
    { 
      overflow = underflow = false;
      if( !setTime( h, m, s)) 
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

    int asSeconds() const          // daytime in seconds
    {
      return (60*60*hour + 60*minute + second);
    } 
    
    DayTime& operator++()          // ++Seconds
    {
      inc();
      return  *this;
    } 
    DayTime operator++(int)        // Seconds++
    {
      DayTime temp(*this);
      inc();
      return temp;
    } 
    
    DayTime& operator--()          // --Seconds
    {
      dec();
      return  *this;
    } 
    DayTime operator--(int)        // Seconds--
    {
      DayTime temp(*this);
      dec();
      return temp;
    } 
};

// ---  Relational operators  ---
//  t1 < t2
inline bool operator<( const DayTime& t1, const DayTime& t2)
{   return  t1.asSeconds() < t2.asSeconds(); } 
 
//  t1 <= t2
inline bool operator<=( const DayTime& t1, const DayTime& t2)
{   return  t1.asSeconds() <= t2.asSeconds(); } 

//  t1 == t2
inline bool operator==( const DayTime& t1, const DayTime& t2)
{   return  t1.asSeconds() == t2.asSeconds(); } 

//  t1 != t2
inline bool operator!=( const DayTime& t1, const DayTime& t2)
{   return !(t1 == t2); } 

//  t1 > t2
inline bool operator>( const DayTime& t1, const DayTime& t2)
{   return (t2 < t1); } 

//  t1 >= t2
inline bool operator>=( const DayTime& t1, const DayTime& t2)
{   return !(t1 < t2); } 

//  ---  Input and Output  ---
ostream& operator<<( ostream& os, const DayTime& t)
{
   os << setfill('0')
      << setw(2) << t.getHour()    << ':'
      << setw(2) << t.getMinute()  << ':'
      << setw(2) << t.getSecond()  << " o'clock";
   os << setfill(' ');
   return os;
}

istream& operator>>( istream& is, DayTime& t)
{
   cout << "Enter daytime in hh:mm:ss format: ";
   int hr = 0, min = 0, sec = 0;
   char c1 = 0, c2 = 0;
   if( !(is >> hr >> c1 >> min >> c2 >> sec)) 
     return is;
   if( c1 != ':' || c2 != ':' || ! t.setTime(hr,min,sec))
     is.setstate( ios::failbit);   // Error! 
                                   //  => Set fail bit.
   return is;
}

#endif   // _DAYTIME_
