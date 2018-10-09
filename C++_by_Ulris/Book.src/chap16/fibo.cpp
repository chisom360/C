// fibo.cpp
// The program computes the first 20 Fibonacci
// numbers and the corresponding Fibonacci quotients.
// -----------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cmath>               // Prototype of sqrt()
#include <string>
using namespace std;

#define COUNT 20

long fib[COUNT + 1] = { 0, 1 };

string header =
" Index   Fibonacci number   Fibonacci quotient    Deviation"
"\n                                                  of limit "
"\n-----------------------------------------------------------";

int main()
{
  int i;
  double q, lim;

  for( i=1; i < COUNT; ++i )        // Computing the 
    fib[i+1] = fib[i] + fib[i-1];   // Fibonacci numbers

  lim = ( 1.0 + sqrt(5.0)) / 2.0;   // Limit

  // Title and the first two Fibonacci numbers:
  cout << header << endl; 
  cout << setw(5) << 0 << setw(15) << fib[0] << endl;
  cout << setw(5) << 1 << setw(15) << fib[1] << endl;

  // Rest of the table:
  for( i=2; i <= COUNT; i++ )
  {                                 // Quotient:
    q = (double)fib[i] / (double)fib[i-1];
 
    cout << setw(5)  << i << setw(15) << fib[i] 
         << setw(20) << fixed << setprecision(10) << q
         << setw(20) << scientific << setprecision(3)
         << lim - q  << endl;
  } 
  return 0;
}

