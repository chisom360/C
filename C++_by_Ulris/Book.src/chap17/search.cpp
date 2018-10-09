// search1.cpp
// A filter, to output all lines containing a given 
// pattern. The function strstr() is called.
// Call:    search1  [ < text.dat ]
// ----------------------------------------------------
#include <iostream>
using namespace std;

#define MAXL  200              // Maximum length of line

namespace MyScope
{                   // Own version of function strstr():
  char *strstr( const char *str, const char *patt); 
}

char line[500],                  // For a line of text.
     patt[] = "is";              // The search pattern.

int main()
{ 
   int lineNr = 0;
                     // As long as a line is left over:
   while( cin.getline( line, MAXL)) 
   {
     ++lineNr;
   
     if( MyScope::strstr( line, patt) != NULL) 
     {                       // If the pattern is found:
        cout.width(3); 
        cout << lineNr << ": "   // Output the line 
             << line << endl;    // number and the line
     }
   }

   return 0;
}
