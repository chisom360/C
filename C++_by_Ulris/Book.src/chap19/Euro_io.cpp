// Euro_io.cpp
// Overload the shift operators 
// for input/output of Euro type objects.
// ----------------------------------------------------
#include "Euro.h"
#include <iostream>
using namespace std;

// Output to stream os.
ostream& operator<<(ostream& os, const Euro& e)
{
    os << e.asString() << " Euro";
    return os;
}

// Input from stream is.
istream& operator>>(istream& is, Euro& e)
{
    cout << "Euro amount (Format ...x.xx): ";

    int euro = 0, cents = 0;
    char c = 0;
    if( !(is >> euro >> c >> cents))           // Input.
      return is;

    if( (c != ',' && c != '.') || cents>=100)  // Error?
      is.setstate( ios::failbit);       // Yes => Set fail bit.
    else
      e = Euro( euro, cents);           // No => Accept value.

    return is;
}
