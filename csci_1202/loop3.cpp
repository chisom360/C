/*     FILE: loop3.cpp     */

/* while loops */
#include <iostream>

using namespace std;

int main( )
{
  const int size = 5;
  int ar[size];
  
  int i;
  i=0;
  while(i < size){
    ar[i] = i+1;
    i++;
  }

  i=0;
  while(i < size){
    cout << "ar[" << i << "] = " << ar[i] << endl;
    i++;
  }

  return 0;
}


/*    OUTPUT: loop3.cpp

	ar[0] = 1
	ar[1] = 2
	ar[2] = 3
	ar[3] = 4
	ar[4] = 5

*/
