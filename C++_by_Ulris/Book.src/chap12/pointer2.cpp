// pointer2.cpp
// Definition and call of function swap().
// Demonstrates the use of pointers as parameters.
// ----------------------------------------------------
#include <iostream>
using namespace std;

void swap( float *, float *);   // Prototype of swap()

int main()
{
   float x = 11.1F;
   float y = 22.2F;

   cout << "x and y before swapping:  "
        << x << "   " << y << endl;
  
   swap( &x, &y );

   cout << "x and y after swapping:   "
        << x << "   " << y << endl;
 
   return 0;
}

void swap( float *p1, float *p2)
{
   float temp;          // Temporary variable 

   temp = *p1;          // At the above call p1 points
   *p1  = *p2;          // to x and p2 to y.
   *p2  = temp;
}
