// ------------------------------------------------------
// Date.h 
// Defines class Date with optimized 
// functionality, e.g. range check.
// ------------------------------------------------------
#ifndef _DATE_   // To avoid multiple inclusions.
#define _DATE_
#include <string>
using namespace std;

class Date
{
  private:
    short day, month, year;
  public: 
    Date()                       // Default constructor
    {
       day = month = year = 1;
    }
    Date( int day, int month, int year)
    {
       if( !setDate( day, month, year) )
         day = month = year = 1;  // If date is incorrect
    } 
    void setDate();              // Sets the current date
    bool setDate( int day, int month, int year);

    int getDay()   const { return day;   }
    int getMonth() const { return month; }
    int getYear()  const { return year;  }

    bool isEqual( const Date& d) const
    {
       return  day == d.day && month == d.month
                            && year  == d.year ;
    }
    bool  isLess( const Date& d) const;
    const string& asString() const;
    void  print(void) const;

    bool isLeapYear()
    {
       return isLeapYear( year);
    }
    static bool isLeapYear( int y)
    {
       return (y%4 == 0 && y%100 != 0) || y%400 == 0;
    }
};


inline bool Date::isLess( const Date& d) const
{
   if( year != d.year)         return year < d.year;
   else if( month != d.month)  return month < d.month;
   else                        return day < d.day;
}

#endif   //  _DATE_

