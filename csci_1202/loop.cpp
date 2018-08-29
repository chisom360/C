/*     FILE: loop.cpp     */

/* for loops */
#include <iostream>

using namespace std;

int main( )
{
  const int size = 5;
  int i = 7;
  int ar[size];
  
  cout << "i = " << i << endl;

  for(int i=0; i<size ; i++)
    ar[i] = i+1;

  for(int i=0; i<size ; i++)
     cout << "ar[" << i << "] = " << ar[i] << endl;

  cout << "i = " << i << endl;

  return 0;
}


/*    OUTPUT: loop.cpp

	i = 7
	ar[0] = 1
	ar[1] = 2
	ar[2] = 3
	ar[3] = 4
	ar[4] = 5
	i = 7

*/
