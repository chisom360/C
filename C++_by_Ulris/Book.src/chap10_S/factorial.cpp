// -----------------------------------------------------
// factorial.cpp 
// Computes the factorial of an integer iteratively, 
// i.e. by a loop, and recursively.
// -----------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

#define N_MAX   20

long double fact1(unsigned int n);  // Iterative solution
long double fact2(unsigned int n);  // Recursive solution

int main()
{
   unsigned int n;

   // Outputs floating point values without decimal places:
   cout << fixed << setprecision(0);

   //  ---  Iterative computation of factorial  --- 

   cout << setw(10) << "n" << setw(30) << "Factorial of n"
        << "           (Iterative solution)\n" 
        << "    -----------------------------------------"
        << endl;

   for( n = 0; n <= N_MAX;  ++n)
      cout << setw(10) << n << setw(30) << fact1(n)
           << endl;

   cout << "\nGo on with <return>";
   cin.get();

   //  ---  Recursive computing of factorial  ---- 

   cout << setw(10) << "n" << setw(30) << "Factorial of n"
        << "           (Recursive solution)\n" 
        << "    -----------------------------------------"
        << endl;

   for( n = 0; n <= N_MAX;  ++n)
      cout << setw(10) << n << setw(30) << fact2(n)
           << endl;

   cout << endl;

   return 0;
}

long double fact1(unsigned int n)        // Iterative 
{                                        // solution.
   long double result = 1.0;

   for( unsigned int i = 2; i <= n; ++i)
       result *= i;

   return result;
}

long double fact2(unsigned int n)        // Recursive 
{                                        // solution.
   if( n <= 1)
      return 1.0;
   else
      return fact2(n-1) * n;
}

