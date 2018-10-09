// -----------------------------------------------------
// TimeTab.cpp 
// An array containing objects of class DayTime.
// -----------------------------------------------------

#include "DayTime.h"      // Definition of class DayTime
#include <iostream>
using namespace std;

char header[] =
"\n\n      ***  Table with Daytimes ***\n\n";

int main()
{
  DayTime timeTab[4] = 
          { 18, DayTime(10,25), DayTime(14,55,30)};
  int i;

  timeTab[3].setTime( 8,40,50);          // Last element.

  cout << header << endl;

  // Output:
  for( i = 0; i < 4; ++i)
  {
     timeTab[i].print();
     cout << endl;
  }

  // To compute shortest and longest time:
  int i_min = 0, i_max = 0;        // Indices for shortest
                                   // und longest element.
  for( i = 1; i < 4; ++i)
  {
     if( timeTab[i].isLess( timeTab[i_min]) )
         i_min = i;
 
     if( timeTab[i_max].isLess( timeTab[i]) )
         i_max = i;
  }

  cout << "\nShortest time: ";  timeTab[i_min].print();

  cout << "\nLongest time: ";  timeTab[i_max].print();

  return 0;
}
