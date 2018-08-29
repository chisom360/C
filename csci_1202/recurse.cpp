/*     FILE: recurse.cpp     */

/* Recursive function examples. */

#include <iostream>
using namespace std;

int factorial(int n);
int fibonacci(int n);

int main( )
{
  int i;

  cout << "Factorial: " << endl; 
  for(int i=0; i< 10; i++)
    cout << i << "! = " 
         << factorial(i) << endl;

  cout << endl << "Fibonacci: " << endl; 
  for(int i=0; i< 10; i++)
    cout << i << " = " 
         << fibonacci(i) << endl;

  return 0;
}

int fibonacci(int n)
{
  if(n <= 0)
    return 0;
  else if(n == 1)
    return 1;
  else if (n == 2)
    return 1;
  else 
    return fibonacci(n-1) + fibonacci(n-2);
}

int factorial(int n)
{
  if(n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else 
    return n * factorial(n-1);	
}


/*    OUTPUT: recurse.cpp

	Factorial: 
	0! = 1
	1! = 1
	2! = 2
	3! = 6
	4! = 24
	5! = 120
	6! = 720
	7! = 5040
	8! = 40320
	9! = 362880
	
	Fibonacci: 
	0 = 0
	1 = 1
	2 = 1
	3 = 2
	4 = 3
	5 = 5
	6 = 8
	7 = 13
	8 = 21
	9 = 34

*/
