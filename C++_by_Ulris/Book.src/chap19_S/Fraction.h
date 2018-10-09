// ------------------------------------------------------
// Fraction.h
// A numeric class to represent fractions
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
    Fraction(long n = 0, long d = 1);

    Fraction operator-() const
    {
       return Fraction(-numerator, denominator);
    }

    Fraction& operator+=(const Fraction& a)
    {
       numerator = a.numerator * denominator 
                   + numerator * a.denominator;
       denominator *= a.denominator;
       return *this;
    }

    Fraction& operator-=(const Fraction& a)
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
 
    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    friend Fraction operator*(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);

    friend ostream& operator<< (ostream& os, const Fraction& a);
    friend istream& operator>> (istream& is, Fraction& a);
};

#endif  // _FRACTION_ 
