/*     FILE: recurse4.cpp     */

/* Recursive function examples. */

// Recursive calls are expensive.

#include <iostream>
using namespace std;

int factorial(int n);
int fibonacci(int n);
void display(char *s, int (*f)(int), int n);

int calls;

int main( )
{

  calls = 0;
  display("Factorial: ", factorial, 10);
  cout << calls << " calls generated." << endl;
  calls = 0;
  cout << endl; 
  display("Fibonacci: ", fibonacci, 10);
  cout << calls << " calls generated." << endl;

  return 0;
}

void display(char *s, int (*f)(int), int n)
{
  cout << s << endl; 
  for(int i=0; i< n; i++)
    cout << i << " = " 
         << f(i) << endl;
  
  return;
}

int fibonacci(int n)
{
  calls++;
  
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
  calls++;
  
  if(n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else 
    return n * factorial(n-1);	
}


/*    OUTPUT: recurse4.cpp

	Factorial: 
	0 = 1
	1 = 1
	2 = 2
	3 = 6
	4 = 24
	5 = 120
	6 = 720
	7 = 5040
	8 = 40320
	9 = 362880
	55 calls generated.
	
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
	168 calls generated.

*/
