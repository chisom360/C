/*     FILE: loop2.cpp     */

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

  while(i < size){
    cout << "ar[" << i << "] = " << ar[i] << endl;
    i++;
  }

  return 0;
}


/*    OUTPUT: loop2.cpp


*/
