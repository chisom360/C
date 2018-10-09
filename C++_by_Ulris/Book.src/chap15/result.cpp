// result.cpp 
// Implementing methods of class Result, 
// which are not inline defined.
// ---------------------------------------------------
#include "result.h"
/*
// Constructors with assignments.

Result::Result() { val = 0.0; }

Result::Result( double w, const DayTime& z)
{
   val = w;    time = z;
}

Result::Result( double w, int hr, int min, int sec)
{
   val = w;
   time = DayTime(hr, min, sec);  // Assign a temporary
                                  // object of type 
}                                 // DayTime to time.
*/

// Constructors with member initializer.

Result::Result() : val(0.0) { }

Result::Result( double w, const DayTime& z)
: val(w), time(z)
{ }
 
Result::Result( double w, int hr, int min, int sec)
: val(w), time(hr, min, sec)
{ }

// Method print().

void Result::print() const
{
   cout << fixed << setprecision(2)
        << setw(8) << val << "      ";
   time.print();
}
