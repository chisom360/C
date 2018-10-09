// ------------------------------------------------------
// Date.cpp 
// Implements those methods of Date class,
// which are not defined inline.
// ------------------------------------------------------

#include "Date.h"               // Class definition
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

// -----------------------------------------------------
void Date::setDate()     // Gets the present date and
{                        // assigns it to the data members.
   struct tm *dur;           // Pointer to struct tm.
   time_t sec;               // For seconds. 

   time(&sec);               // Gets the present time.
   dur = localtime(&sec);    // Initializes a struct of 
                             // type tm and returns a
                             // pointer to it.
   day   = (short) dur->tm_mday;
   month = (short) dur->tm_mon + 1;
   year  = (short) dur->tm_year + 1900;
}


// -----------------------------------------------------
bool Date::setDate( int mn, int da, int yr)  
{
   if( mn < 1 ||  mn > 12 ) return false;
   if( da < 1 ||  da > 31 ) return false;

   switch(mn)             // Month with less than 31 days
   {
     case 2:  if( isLeapYear(yr))
              {
                if( da > 29)
                  return false;
              }
              else if( da > 28)
                return false;
              break;
     case 4:
     case 6:
     case 9:
     case 11:
              if( da > 30)  return false;
   }
   month = (short) mn;
   day   = (short) da;
   year  = (short) yr;
   return true;
}

// -----------------------------------------------------
void Date::print() const              // Output a date
{
    cout << asString() << endl;
}

// -----------------------------------------------------
const string& Date::asString() const   // Return a date 
{                                      // as string.
   static string dateString;
   stringstream iostream;              // For conversion
                                       // number -> string
   iostream << setfill('0')            // and formatting.
            << setw(2) << month << '-'
            << setw(2) << day   << '-' << year;

   iostream >> dateString;

   return dateString;
}

