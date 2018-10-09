// ----------------------------------------------------
// scroll.cpp 
// Scrolling a message.
// ----------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

#define DELAY  10000000L                // Output delay 

inline void cls()                       // Clear screen
{
   cout << "\033[2J\n";
}

inline void locate(int z, int s)   // Put cursor in row z
{                                  // and column s
   cout << "\033[" << z << ';' << s << 'H';
}

char mess[] = "* * *  B R E A K  * * * ";

int main()
{
   int i, start = 0, len = strlen(mess);

   cls();  locate(24, 20);        // Row 24, column 20
   cout << "---  Press interrupt key to terminate (^C)  ---"; 

   while( true )
   {
     locate( 12, 25);            // Row 12, column 25
     i = start;                  // Output from index start

     do
     {
         cout << mess[i++];
         i = i % len;            // if( i == len) i = 0;
     }
     while( i != start);

     // Wait in short
     for( int count = 0; count < DELAY; ++count)
         ;

     ++start;                     // For next output
     start %= len;                // start = start % len;
   }
   
   cls();
   
   return 0;
}
