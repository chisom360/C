// Ref1.cpp 
// Demonstrates the definition and use of references.
// ---------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

float x = 10.7F;                           // Global

int main()
{
   float  &rx = x;          // Local reference to x
// double &ref = x;         // Error: different type!

   rx *= 2;

   cout << "   x = " <<  x << endl    //  x = 21.4
        << "  rx = " << rx << endl;   // rx = 21.4

   const float& cref = x;    // Read-only reference
   cout << "cref = " <<  cref << endl;   // ok!
// ++cref;                   // Error: read-only!

   const string str = "I am a constant string!"; 

// str = "That doesn't work!";  // Error: str constant! 
// string& text = str;          // Error: str constant!
   const string& text = str;    // ok! 
   cout << text << endl;        // ok! Just reading.
   return 0;
}
