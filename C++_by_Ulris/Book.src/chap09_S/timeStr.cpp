// timeStr.cpp 
// Demonstrates operations on a string containing
// the present time.

#include <iostream>
#include <string>
#include <ctime>         // for time(), ctime(), ...
using namespace std;

int main()
{
   long sec;
   time( &sec);            // Reads the present time 
                           // (in seconds) into sec.
   string tm = ctime( &sec);     // Converts the 
                                 // seconds to a string.

   cout << "Date and time: " << tm << endl;

   string hr(tm, 11, 2);  // Substring of tm starting at
                          // position 11, 2 characters long.
   string greeting("Have a wonderful ");

   if( hr < "10")             // Compares strings 
       greeting += "Morning!";
   else if( hr < "17") 
       greeting += "Day!";
   else
       greeting += "Evening!";

   cout << greeting << endl; 

   return 0;
}

