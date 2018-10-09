// -------------------------------------------------------
// fraction.cpp
// Defines methods and friend functions.
// -------------------------------------------------------

#include "Fraction.h"

// Constructor:
Fraction::Fraction(long z, long n)
{
   if(n == 0) throw DivisionByZero(); 
   if(n < 0)  z = -z, n = -n;
   numerator = z;
   denominator  = n;
}

Fraction operator+( const Fraction& a, const Fraction& b)
{
   Fraction temp;
   temp.denominator = a.denominator * b.denominator;
   temp.numerator = a.numerator*b.denominator
                  + b.numerator * a.denominator;
   return temp;
}

Fraction operator-( const Fraction& a, const Fraction& b )
{
   Fraction temp = a;   temp += (-b);
   return temp;
}

Fraction operator*(const Fraction& a, const Fraction& b )
{
   Fraction temp;
   temp.numerator   = a.numerator * b.numerator;
   temp.denominator = a.denominator * b.denominator;
   return temp;
}

Fraction operator/(const Fraction& a, const Fraction& b )
{
   if( b.numerator == 0)  throw Fraction::DivisionByZero();
   // To multiply a with the inverse of b:
   Fraction temp; 
   temp.numerator = a.numerator * b.denominator;
   temp.denominator = a.denominator * b.numerator;

   if( temp.denominator < 0 )
     temp.numerator   = -temp.numerator,
     temp.denominator = -temp.denominator;

   return temp;
}

ostream& operator<<(ostream& os, const Fraction& a)
{
   os << a.numerator << "/" << a.denominator;
   return os;
}

istream& operator>>(istream& is, Fraction& a)
{
   cout << "Enter a fraction:\n"
           "  Numerator:         ";   is >> a.numerator;
   cout << "  Denominator != 0:  ";   is >> a.denominator;

   if( !is.fail() && a.denominator == 0)
   {
      cout << "\nError: The denominator is 0\n"
           << "  New Denominator != 0: ";
      is >> a.denominator;
   }
   if( is.fail() || a.denominator == 0)
      throw Fraction::DivisionByZero();

   if( a.denominator < 0 )
      a.numerator   = -a.numerator,
      a.denominator = -a.denominator;

  return is;
}
