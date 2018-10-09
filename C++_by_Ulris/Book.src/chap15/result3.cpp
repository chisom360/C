// result3.cpp 
// Defining static data elements and 
// methods, which are not defined inline.
// ---------------------------------------------------

#include "result3.h"

double Result::min = 0.0;
double Result::max = 0.0;

bool   Result::first = true;

void Result::setMinMax(double w)   // Help function
{
   if(first) {  min = max = w;   first = false; }
   else if( w < min)  min = w;
   else if( w > max)  max = w;
}
 
// Constructors with member initializer.
Result::Result( double w, const DayTime& z)
: val(w), time(z)
{  setMinMax(w);  }

Result::Result( double w, int hr, int min, int sec)
: val(w), time(hr, min, sec)
{  setMinMax(w);  }



void Result::print() const
{
   cout << fixed << setprecision(2)
        << setw(8) << val << "      ";
   time.print();
}
