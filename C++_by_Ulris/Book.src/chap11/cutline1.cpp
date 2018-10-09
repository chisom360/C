// Cutline1.cpp 
// A filter to remove white space characters 
// at the end of lines.
// Call:    cutline [ < source]  [ > destination]
// --------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

void cutline( void );         // Prototype
string line;                  // Global string

int main()
{
   while( getline(cin, line)) // As long as a line 
   {                          // can be read. 
     cutline();               // Shorten the line.
//     cout << line << endl;    // Output the line.
     cout << line << '!' << endl;    // Output the line.
   }
   return 0;
}

