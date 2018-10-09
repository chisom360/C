// ----------------------------------------------------
// DayTim_t.cpp 
// Testing the operators of class DayTime.
// ----------------------------------------------------
#include "DayTime.h"         // Definition of the class
#include <iostream>
using namespace std;

int main()
{
   DayTime cinema( 20,30);
   cout << "\nThe movie starts at " << cinema << endl;

   DayTime now;
   cout << "What time is it now?" << endl;
   if( !(cin >> now) )
      cerr << "Invalid input!" << endl;
   else
      cout << "\nThe time is now" << now << endl;

   cout << "\nThe movie has ";
   if( cinema < now)
      cout << "already begun!\n" << endl;
   else
      cout << "not yet begun!\n" << endl;

   cout << "Now it is     " << now++ << endl;
   cout << "After 2 seconds: " << ++now << endl;

   DayTime depart(16,0);
   cout << "Let's go at " << --depart << endl;

   if( depart >= now )
      cout << "You can ride with us!" << endl;
   else
      cout << "You are too late!" << endl;

   return 0;
}
