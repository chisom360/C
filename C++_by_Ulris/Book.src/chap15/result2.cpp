// Result2.cpp 
// Implements the methods of class Result, 
// which are not defined inline.
// ---------------------------------------------------

#include "result2.h"

// Constructors with member initializer.

Result::Result( double w, const DayTime& z)
: val(w), time(z)
{  }
 
Result::Result( double w, int hr, int min, int sec)
: val(w), time(hr, min, sec)
{}

void Result::print() const
{
   cout << fixed << setprecision(2)
        << setw(8) << val << "      ";
   time.print();
}
