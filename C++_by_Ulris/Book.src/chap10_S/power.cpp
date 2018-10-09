// -----------------------------------------------------
// power.cpp 
// Defines and calls the function pow() to compute
// integer powers of a floating point number.
// Overloading the standard function pow().
// -----------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

double pow(double base, int exp);

int main()       // Tests the self defined function pow()
{
   double base     = 0.0;
   int    exponent = 0;

   cout << "  **** Computing Integer Powers ****\n"
        << endl;

   cout << "Enter test values.\n"
        << "Base (floating point): ";  cin >> base;
   cout << "Exponent (integer):    ";  cin >> exponent;

   cout << "Result of " << base << " to the power of "
        << exponent << " = " << pow( base, exponent) 
        << endl;

   cout << "Computing with the standard function: " 
        << pow( base, (double)exponent) << endl;

   return 0;
}

double pow(double base, int exp) 
{
    if( exp == 0)     return 1.0;

    if( base == 0.0)
        if( exp > 0)  return 0.0;
        else          return HUGE_VAL;

    if( exp < 0) 
    {
       base = 1.0 / base;
       exp = -exp;
    }
    double power = 1.0;
    for( int n = 1; n <= exp; ++n)
        power *= base;

    return power;
}
