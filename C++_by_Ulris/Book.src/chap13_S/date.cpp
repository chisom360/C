// ----------------------------------------------------
// date.cpp 
// Implementing the methods of class Date.
// ----------------------------------------------------

#include "date.h"

#include <iostream>
#include <ctime>
using namespace std;

// ---------------------------------------------------
void Date::init(void)    // Get the present date and 
{                        // assign it to data members.
   struct tm *ptr;              // Pointer to struct tm.
   time_t sec;                  // For seconds. 

   time(&sec);               // Get the present date.
   ptr = localtime(&sec);    // Initialize a struct of 
                             // type tm and return a 
                             // pointer to it.
   month = (short) ptr->tm_mon + 1;
   day   = (short) ptr->tm_mday;
   year  = (short) ptr->tm_year + 1900;
}

 

// ---------------------------------------------------
void Date::init( int m, int d, int y)  
{
   month = (short) m;
   day   = (short) d;
   year  = (short) y;
}

// ---------------------------------------------------
void Date::print(void)           // Output the date
{
   cout << month << '-' << day << '-' << year
        << endl;
}
