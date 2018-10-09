// result_t.cpp 
// Tests constructors of class Result
// ---------------------------------------------------

#include "Result.h"
#include <iostream>
using namespace std;

int main()        // Some air temperature measurements
{
   DayTime  morning(6,30);

   Result t1,                  // Default constructor
          t2( 12.5, morning),
          t3( 18.2, 12,0,0), 
          t4( 17.7);           // At current time
 
    cout << "Default values: ";   t1.print();
 
    cout << "\n Temperature   Time  \n"
         << "-------------------------" << endl;
    
    t2.print();
    t3.print();
    t4.print();
    cout << endl;
    
    return 0;
}
