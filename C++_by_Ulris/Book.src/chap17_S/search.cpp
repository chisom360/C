// -------------------------------------------------------
// search.cpp
// A filter that outputs all lines containing a certain 
// pattern. The standard function strstr() is called.
//
// Call:    search  pattern [ < text.dat ]
//
// If no file name is passed the input is read from the 
// keyboard. In this case end input with <Ctrl> + <Z>.
// ------------------------------------------------------

#include <iostream>
#include <cstring>      // Standard functions for C strings
using namespace std;
#define MAXL  200                // Maximum length of line
char line[500];                  // For a line of text.
 

int main( int argc, char *argv[])
{
   if( argc != 2)
   {
     cerr << "Call:  search  pattern [ < text.dat ]"
          << endl;
     return 1;
   }
    
   int lineNr = 0;
                            // As long as a line exists:
   while( cin.getline( line, MAXL)) 
   {
     ++lineNr;
     if( strstr( line, argv[1]) != NULL)
     {                         // If the pattern was found:
        cout.width(3); 
        cout << lineNr << ": "       // Output the line
             << line << endl;        // number and the line
     }
   }
   return 0;
}
