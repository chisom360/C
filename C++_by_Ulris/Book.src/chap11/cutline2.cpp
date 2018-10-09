// Cutline2.cpp
// Containing the function cutline(), which removes blanks
// and tabulator characters at the end of the string line.
// The string line has to be globally defined in another 
// source file.
// --------------------------------------------------

#include <string>
using namespace std;

extern string line;             // extern declaration

void cutline()
{
   int i = line.size();         // Position after the 
                                // last character.
   while( --i >= 0 )
     if(   line[i] != ' '       // If no blank and 
        && line[i] != '\t' )    // no tab
       break;                   // -> stop the loop.

   line.resize(++i);            // Fix new length.
}
