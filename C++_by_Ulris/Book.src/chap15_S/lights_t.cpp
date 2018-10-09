// -----------------------------------------------------
// Lights_t.cpp : Simulates two traffic lights.
// -----------------------------------------------------

#include "lights.h"       // Definition of class Lights
#include <iostream>
#include <ctime>          // Standard function time()
using namespace std;

inline void wait( int sec)        // Wait sec seconds.
{  time_t end = time(NULL) + sec;
   while( time(NULL) < end)
      ;
}

// Alternative for Windows:
// #include <windows.h>
// inline void wait( int sec) {  Sleep( 1000 * sec); }

Lights A1, A2;                        // Traffic lights and

enum { greenTime1 = 10 , yellowTime1 = 1,  // time to wait.
       greenTime2 = 14 , yellowTime2 = 2  };

int main() 
{  
   cout << "Simulating two traffic lights!\n\n"
        << "Terminate this program with <Strg>+<C>!\n"
        << endl;
   
   cout << "  1. Light     2. Light\n"
        << "---------------------------" << endl;
   
   while(true)
   {  
      A1.setState( Lights::red);           // A1 = red
      
      A2.setState( Lights::yellow);   cout << endl;
      wait( yellowTime2);
      cout << "             ";
      
      A2.setState( Lights::green);  cout << endl;
      wait(greenTime2);
      cout << "             ";
      
      A2.setState( Lights::yellow);   cout << endl;
      wait(yellowTime2);
      
      A1.setState( Lights::yellow);          // A2 = red
      
      A2.setState( Lights::red);    cout << endl;
      wait(yellowTime1);
      
      A1.setState( Lights::green);  cout << endl;
      wait(greenTime1);
      
      A1.setState( Lights::yellow);   cout << endl;
      wait(yellowTime1);
   }
   
   return 0;
}





/* Output:

Simulating two traffic lights!

Terminate this program with <Strg>+<C>!

  1. Light     2. Light
---------------------------
    RED          YELLOW
                 GREEN
                 YELLOW
    YELLOW         RED
    GREEN
    YELLOW
    RED          YELLOW
                 GREEN

*/