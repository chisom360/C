// ------------------------------------------------------
// fraction.h
// A numerical class to represent fractions 
// exception handling included.
// ------------------------------------------------------

#ifndef _FRACTION_
#define _FRACTION_

#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction
{
  private:
   long numerator, denominator;

  public:
   class DivisionByZero
   {
       // No data elements
   };
   Fraction( long z = 0, long n = 1) throw(DivisionByZero);
   Fraction operator-() const
   {
      return Fraction(-numerator, denominator);
   }

   Fraction& operator+=( const Fraction& a)
   {
      numerator = a.numerator * denominator 
                 + numerator * a.denominator;
      denominator *= a.denominator;
      return *this;
   }

   Fraction& operator-=( const Fraction& a)
   {
      *this += (-a);
      return *this;
   }

   Fraction& operator++()
   {
      numerator += denominator;
      return *this;
   }

   Fraction& operator--()
   {
      numerator -= denominator;
      return *this;
   }

   friend Fraction operator+( const Fraction&, const Fraction&);
   friend Fraction operator-( const Fraction&, const Fraction&);
   friend Fraction operator*( const Fraction&, const Fraction&);
   friend Fraction operator/( const Fraction&, const Fraction&)
                                    throw(Fraction::DivisionByZero); 

   friend ostream& operator<<( ostream&, const Fraction&);
   friend istream& operator>>( istream& is, Fraction& a)
                                    throw(Fraction::DivisionByZero);
};

#endif

