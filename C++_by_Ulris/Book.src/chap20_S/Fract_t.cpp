// -------------------------------------------------------
// Fract_t.cpp
// Tests the class Fraction with type conversions.
// -------------------------------------------------------

#include "Fraction.h"

int main()
{
   Fraction a, b(-1,5), c(2.25);
   double x = 0.5, y;

   a = x;                    // double -> Fraction 
   cout << "\nSome test results:" << endl;
   cout << " a = " << a << endl;
   cout << " b = " << b << endl;
   cout << " c = " << c << endl;

   cout << "\nThe fractions as double values:" << endl;
                             // Fraction -> double:
   cout << " a = " << (double)a << endl;
   cout << " b = " << (double)b << endl;
   cout << " c = " << (double)c << endl;

   cout << "\nAnd calculate with:" << endl;
   cout << " a + b = " << (a + b) << endl;
   cout << " a - b = " << (a - b) << endl;
   cout << " a * b = " << (a * b) << endl;
   cout << " a / b = " << (a / b) << endl;

   cin  >> a;                // Enter a fraction.
   cout << "\nYour input:    " << a << endl;

   a.simplify();
   cout << "\nSimplified:        " << a << endl;
   cout << "\nAs double value: " << (double)a << endl;

   cout << "\nEnter a floating point value: ";  cin >> x; 
   cout << "\nThis is in fraction form:            " 
        << (Fraction)x << endl;

// To calculate the sum b + x : 
   cout << " b = " << b << endl;
   cout << " x = " << x << endl;
// a = b + x;                 // Error: ambiguous!
   a = b + Fraction(x);       // ok! To compute fractions.
   y = (double)b + x;         // ok! To compute doubles.

   cout << " b + x  as fraction:   " << a << endl;
   cout << " b + x  as double:     " << y << endl;

   return 0;
}
