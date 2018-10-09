// -------------------------------------------------------
// Fraction.cpp
// Defining methods and friend functions.
// -------------------------------------------------------

#include "Fraction.h"

// Constructor:
Fraction::Fraction(long n, long d)
{
  if(d == 0)
  { cerr << "\nError: Division by zero!\n";
    exit(1);
  }
  if( n < 0 ) n = -n, d = -d;
  numerator = n;
  denominator  = d;
}
Fraction operator+(const Fraction& a, const Fraction& b)
{
   Fraction temp;
   temp.denominator = a.denominator * b.denominator;
   temp.numerator = a.numerator*b.denominator
                  + b.numerator * a.denominator;
   return temp;
}

Fraction operator-(const Fraction& a, const Fraction& b )
{
   Fraction temp = a;   temp += (-b);
   return temp;
}

Fraction operator*(const Fraction& a, const Fraction& b )
{
   Fraction temp;
   temp.numerator   = a.numerator * b.numerator;
   temp.denominator = a.denominator  * b.denominator;
   return temp;
}


Fraction operator/(const Fraction& a, const Fraction& b )
{
   if( b.numerator == 0)
   {
     cerr << "\nError: Division by zero!\n";
     exit(1);
   }
   // To multiply a by the inverse of b:
   Fraction temp; 
   temp.numerator = a.numerator * b.denominator;
   temp.denominator = a.denominator  * b.numerator;

   if( temp.denominator < 0 )
     temp.numerator = -temp.numerator,
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
