// mini_t.cpp: Passing arguments to 
//             function templates
// ----------------------------------------------

#include <iostream>
using namespace std;

template <class T>
T min( T x, T y)
{
   return( (x < y) ? x : y);
}

int main()
{
   short x = 10, y = 2;

   cout << "x = " << x << "  y = " << y << endl;
   cout << "The smaller value is: "   
        << min(x, y) << endl;      // Call is o.k.

   double z1 = 2.2;
   float  z2 = 1.1F;

//   cout << "\nThe smaller value is: "   
//        << min(z1, z2) << endl;    // Not o.k.

   double z3 = 1.1;
   cout << "\nz1 = " << z1
        << "  z3 = " << z3 << endl;
   cout << "The smaller value is: " 
        << min(z1, z3) << endl;    // Call is o.k.

   return 0;
}
