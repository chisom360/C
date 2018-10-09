// ----------------------------------------------------
// swap.cpp
// Definition and call of the function swap().
// 1. version: parameters with pointer type,
// 2. version: parameters with reference type.
// ----------------------------------------------------
#include <iostream>
using namespace std;

void swap( float*, float*);      // Prototypes of swap()
void swap( float&, float&);

int main()
{
   float x = 11.1F;
   float y = 22.2F;

   cout << "x and y before swapping:   "
        << x << "   " << y << endl;

   swap( &x, &y);           // Call pointer version.

   cout << "x and y after 1. swapping: "
        << x << "   " << y << endl;

   swap( x, y);             // Call reference version.

   cout << "x and y after 2. swapping: "
        << x << "   " << y << endl;

   return 0;
}

void swap(float *p1, float *p2)     // Pointer version
{
   float temp;                      // Temporary variable

   temp = *p1;                      // Above call points p1
   *p1  = *p2;                      // to x and p2 to y.
   *p2  = temp;
}

void swap(float& a, float& b)       // Reference version
{
   float temp;                      // Temporary variable

   temp = a;                        // For above call
   a    = b;                        // a equals x and 
   b    = temp;                     // b equals y.
}
