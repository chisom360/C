// -------------------------------------------------------
// Fract_t.cpp
// Testing the class Fraction.
// Modules: Fract_t.cpp  Fraction.cpp
// -------------------------------------------------------

#include "Fraction.h"

int main()
{
   Fraction a(1,3), b(4);

   cout << "\nSome test results:\n\n";

   cout << " a = " << a << endl;
   cout << " b = " << b << endl;

   cout << " a + b = " << (a + b) << endl;
   cout << " a - b = " << (a - b) << endl;
   cout << " a * b = " << (a * b) << endl;
   cout << " a / b = " << (a / b) << endl;

   cout << " --a = " <<  --a << endl;
   cout << " ++a = " <<  ++a << endl;

   a += Fraction(1,2);
   cout << " a+= 1/2;  a = " << a << endl;

   a -= Fraction(1,2);
   cout << " a-= 1/2;  a = " << a << endl;

   cout << "-b = " << -b << endl;

   cout << "\nAnd now an input\n";
   cin  >> a;
   cout << "\nYour input: " << a << endl;

   return 0;
}
