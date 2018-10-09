// -------------------------------------------------------
// Fraction.cpp
// Defining methods and friend functions
// that are not inline.
// -------------------------------------------------------

#include "Fraction.h"

// Constructors:
Fraction::Fraction(long n, long d)
{
   if(d == 0)
   {
     cerr << "\nError: Division by zero!\n";
     exit(1);
   }
   if( d < 0 )
      n = -n, d= -d;
   numerator = n;
   denominator  = d;
}
Fraction::Fraction( double x)
{
   x *= 1000.0;
   x += (x>=0.0) ? 0.5 : -0.5;    // Round the 4. digit.
   numerator = (long)x;
   denominator = 1000;
   simplify();
}

Fraction operator+(const Fraction& a, const Fraction& b )
{
   Fraction temp;

   temp.denominator = a.denominator * b.denominator;
   temp.numerator = a.numerator*b.denominator + b.numerator * a.denominator;
   temp.simplify();
   return temp;
}

Fraction operator-(const Fraction& a, const Fraction& b )
{
   Fraction temp = a;
   temp += (-b);
   return temp;
}

Fraction operator*(const Fraction& a, const Fraction& b )
{
   Fraction temp;

   temp.numerator = a.numerator * b.numerator;
   temp.denominator  = a.denominator  * b.denominator;
   temp.simplify();

   return temp;
}

Fraction operator/(const Fraction& a, const Fraction& b )
{
   if( b.numerator == 0)
   {
     cerr << "\nError: Division by zero!\n";
     exit(1);
   }

   Fraction temp;      // To multiply a with the inverse of b 
   temp.numerator = a.numerator * b.denominator;
   temp.denominator = a.denominator  * b.numerator;

   if( temp.denominator < 0 )
     temp.numerator = -temp.numerator,
     temp.denominator = -temp.denominator;

   temp.simplify();

   return temp;
}

ostream& operator<<(ostream& os, const Fraction& a)
{
  os << a.numerator << "/" << a.denominator;
  return os;
}

istream& operator>>(istream& is, Fraction& a)
{
  cout << "\nEnter a fraction:\n"
          "  Numerator:        ";   is >> a.numerator;
  cout << "  Denominator != 0: ";   is >> a.denominator;

  if( !is) return is;

  if( a.denominator == 0)
  {
     cout << "\nError: The denominator is 0\n"
             "  New denominator != 0: ";   is >> a.denominator;

     if( a.denominator == 0)
     {
       cerr << "\nError: Division by zero!\n";
       exit(1);
     }
  }
  if( a.denominator < 0 )
     a.numerator = -a.numerator,
     a.denominator = -a.denominator;

  return is;
}

// To simplify fractions:
void Fraction::simplify()
{
   // Divide the numerator and denominator by
   // the greatest common divisor.

   if( numerator == 0) 
   {
       denominator = 1;
       return;
   }

   // Calculating the greatest common divisor
   // using an algorithm by Euclid.
   long a = (numerator < 0) ? -numerator : numerator,
        b = denominator, 
        help;

   while( b != 0)
   {
       help = a % b;  a = b;  b = help;
   }
   // a is the greatest common divisor
   numerator /= a;
   denominator  /= a;
} 
