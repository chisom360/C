/*     FILE: arrayParam2.cpp     */

/* Passing arrays as parameters. */

// size is clearly not a factor for the parameter

#include <iostream>
using namespace std;

const int size = 15;

void displayIntArray(int n[size]);


int main( )
{
  int ar[size];

  for(int i=0; i< size; i++)
    ar[i] = i*3;

  displayIntArray(ar);
  return 0;
}

void displayIntArray(int n[50])
{
  for(int i=0; i< size; i++)
    cout << "n[" << i << "] = " << n[i] << endl;
}


/*    OUTPUT: arrayParam2.cpp

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
