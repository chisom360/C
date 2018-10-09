// -------------------------------------------------------
// fract_t.cpp : Testing the class Fraction.
// Modules: fract_t.cpp  fraction.cpp
// -------------------------------------------------------

#include "fraction.h"

int main()
{
   try        // Tests the exception of the constructor:
   {
      Fraction c(5,0);
   }
   catch(Fraction::DivisionByZero& ) 
   {
     cout << "\nError on initializing: "
          << "\nThe denominator is 0\n";
   }
 
   Fraction a(1,3), b(3);

   try
   {
     cout << "\nSome test outputs:\n\n";

     cout << " a = " << a << endl;
     cout << " b = " << b << endl;

     cout << " a + b = " << (a + b) << endl;
     cout << " a - b = " << (a - b) << endl;
     cout << " a * b = " << (a * b) << endl;
     b = 0;
     cout << " a / b = " << (a / b) << endl;   // Error!
   }
   catch(Fraction::DivisionByZero& ) 
   {
     cout << "\nError on dividing: "
          << "\nNo division by zero! 0\n";
   }

   cout << "  --a =  " <<  --a << endl;
   cout << "  ++a  = " <<  ++a << endl;

   a += Fraction(1,2);
   cout << " a+= 1/2;  a = " << a << endl;

   a -= Fraction(1,2);
   cout << " a-= 1/2;  a = " << a << endl;

   cout << "-b = " << -b << endl;

   cout << "\nAnd now your input: \n";
   try
   {
      cin  >> a;
   }
   catch(Fraction::DivisionByZero&) 
   {
      cerr << "\nError: The denominator is 0\n";
      exit(1);       
   }

   cout << "\nYour input: " << a  << endl;

   return 0;
}
