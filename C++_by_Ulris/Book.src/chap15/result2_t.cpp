// result2_t.cpp  :     Tests the new class Result.
// ---------------------------------------------------

#include "result2.h"
#include <iostream>
using namespace std;

int main() 
{
   DayTime  start(10,15);

   Result m1( 101.01, start),
          m2( m1),            // Copy constructor ok!
          m3( 99.9);          // At current time.

// m2 = m3;         // Error! Standard assignment incorrect.
   m2.setVal(100.9);          // Corrected value for m2

   cout << "\n  Result        Time  \n"
        << "-------------------------" << endl;
   m1.print();
   m2.print();
   m3.print();
   cout << endl;

   return 0;
}
