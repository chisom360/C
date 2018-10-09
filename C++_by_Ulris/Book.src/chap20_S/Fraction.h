// --------------------------------------------------------
// Fraction.h (Chapter 20)
// A numerical class to represent fractions.
// The class converts Fraction <--> double
// and simplifying fractions.
// --------------------------------------------------------

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
   Fraction(long z, long n);
   Fraction(double x);              // double-constructor

   // Default- long- and int-constructor:
   Fraction(long z=0) : numerator(z), denominator(1) {}
   Fraction(int z) : numerator(z), denominator(1) {}

   void simplify();

   operator double()                // Fraction -> double                
   {
       return (double)numerator / (double)denominator;
   }
   
   Fraction operator-() const
   {
      return Fraction(-numerator, denominator);
   }

   Fraction& operator+=(const Fraction& a)
   {
      numerator = a.numerator * denominator + numerator * a.denominator;
      denominator *= a.denominator;
      simplify();
      return *this;
   }

   Fraction& operator-=(const Fraction& a)
   {
      *this += (-a);
      simplify();
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

   friend Fraction operator+ (const Fraction&, const Fraction& );
   friend Fraction operator- (const Fraction&, const Fraction& );
   friend Fraction operator* (const Fraction&, const Fraction&);
   friend Fraction operator/ (const Fraction&, const Fraction&);

   friend ostream& operator<< (ostream& os, const Fraction& a);
   friend istream& operator>> (istream& is, Fraction& a);
};

#endif
