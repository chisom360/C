/*     FILE: arrayParam5.cpp     */

/* Passing arrays as parameters. */

// Parameter is actually an address

#include <iostream>
using namespace std;

const int size = 15;

void displayIntArray(int [ ], int);


int main( )
{
  int ar[size];

  for(int i=0; i< size; i++)
    ar[i] = i*3;

  displayIntArray(ar, size);
  return 0;
}

void displayIntArray(int * n, int sz)
{
  for(int i=0; i< sz; i++)
    cout << "n[" << i << "] = " << n[i] << endl;
}


/*    OUTPUT: arrayParam5.cpp

	n[0] = 0
	n[1] = 3
	n[2] = 6
	n[3] = 9
	n[4] = 12
	n[5] = 15
	n[6] = 18
	n[7] = 21
	n[8] = 24
	n[9] = 27
	n[10] = 30
	n[11] = 33
	n[12] = 36
	n[13] = 39
	n[14] = 42

*/
