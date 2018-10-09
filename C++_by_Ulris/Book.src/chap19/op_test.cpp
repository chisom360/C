// op_test.cpp 
// Testing the operators < and ++ of class DayTime.
// ---------------------------------------------------

#include "DayTime.h"         // Definition of the class
#include <iostream>
using namespace std;

const DayTime& currentTime();    // Current time

int main()
{
   DayTime cinema( 20,30);

   cout << "\nThe movie starts at ";
   cinema.print();

   DayTime now( currentTime());
   cout << "\nNow it is ";  now.print();

   cout << "\nThe cinema has ";
   if( cinema < now)
      cout << "already begun!\n" << endl;
   else
      cout << "not yet begun!\n" << endl;

   ++now;
   cout << "\nNow it is ";  now.print();

   DayTime depart1( 11, 11, 11), depart2(12,0,0);

   if( depart1 < depart2 )
     cout << "\nThe 1st plane takes off earlier!" << endl;

  return 0;
}
