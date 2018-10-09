// --------------------------------------------------- 
//  NoCtrl.cpp
//  Filter to ignore control characters
//  To call e.g.:  NoCtrl < file
// --------------------------------------------------- 

#include <iostream>
using namespace std;

#define isCtrl(c)    ( c >= 0  &&  c <= 31  \
                               && c != '\n' && c != '\t')

int main()
{
   char c, prec = 0;           // Character and predecessor.
   long nCtrl = 0, nChar = 0;  // Number of following 
                               // control characters or
                               // other characters
   while( cin.get(c))
   { 
     if( isCtrl(c))            // Control characters
     {
         ++nCtrl;
         nChar = 0;
     }
     else                      // Normal character
     {
        if( nCtrl > 0)
        {
           cout.put(' ');
           nCtrl = 0;
        }
        switch( ++nChar)
        {
           case 1:   break;
           case 2:   cout.put(prec);    // Predecessor and
           default:  cout.put(c);       // actual character
        }
        prec = c;
     }
   }
   return 0;
}
