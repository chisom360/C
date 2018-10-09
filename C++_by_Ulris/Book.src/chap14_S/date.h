// ------------------------------------------------------
// Date.h 
// Defining class Date with optimized 
// functionality, e.g. range check.
// ------------------------------------------------------

#ifndef _DATE_   // Avoids multiple inclusions.
#define _DATE_

#include <string>
using namespace std;

class Date
{
  private:
    short month, day, year;

  public: 
    Date()                        // Default constructor
    {  month = day = year = 1;  }

    Date( int month, int day, int year)
    {
       if( !setDate( month,  day, year) )
         month = day = year = 1;  // If date is invalid
    } 
    void setDate();               // Sets the current date
    bool setDate( int month, int day, int year);

    int getMonth() const { return month; }
    int getDay()   const { return day;   }
    int getYear()  const { return year;  }

    bool isEqual( const Date& d) const
    {
       return month == d.month && day == d.day
                            && year  == d.year ;
    }
    bool isLess( const Date& d) const;
    const string& asString() const;
    void print(void) const;
};
 
inline bool Date::isLess( const Date& d) const
{
   if( year != d.year)         return year < d.year;
   else if( month != d.month)  return month < d.month;
   else                        return day < d.day;
}

inline bool isLeapYear( int year)
{
   return (year%4 == 0 && year%100 != 0) || year%400 == 0;
}

#endif   //  _DATE_
