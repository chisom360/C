// -------------------------------------------------------
//  hide_t.cpp:  Filter to encrypt data. 
//               Swap bits in bit positions 5 and 6, 
//               0 and 4,  1 and 3 for all characters
//               except control characters.
//               Modules:  hide_t.cpp,  swapbits.cpp  
// 
//  Call:       hide_t [ < sourcefile ] [ > destfile ] 
// -------------------------------------------------------

#include <iostream>
using namespace std;

int swapbits( int ch, int bitnr1, int bitnr2); // Prototype

int main()                            // To encrypt data
{
   int c;
   while( (c = cin.get()) != EOF)
   {
      if( c >= 32)                    // Control character? 
      {
         c = swapbits(c, 5, 6);       // Swap bits 
         c = swapbits(c, 0, 4);
         c = swapbits(c, 1, 3);
      }
      cout << (char)c;
   }
   return 0;
}
