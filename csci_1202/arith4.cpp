/*     FILE: arith4.cpp     */

/*
    A new class of arrays, based on safe_array, that can
    perform arithmetic between arrays.
    
    Class arithmetic_array moved out into its own set of
    files. 
*/
#include <iostream>

#include "arith_ar.h"
using namespace std;

int main( )
{
  arithmetic_array ar(5);
  arithmetic_array ar2(5);
  arithmetic_array ar3(7);

  for(int i=0; i<ar.getSize( ); i++)
    ar[i] = i;

  ar2 = 10 * ar;

  for(int i=0; i<ar3.getSize( ); i++)
    ar3[i] = i*2;

  if (ar2.getSize( ) == ar.getSize( ))  // Check sizes of arrays first
    ar2 = ar + ar2;    // Illegal addition, if size mismatch

  for(int i=0; i<ar2.getSize( ); i++)   // display array ar2
    cout << "ar2[" << i << "] = " << ar2[i] << endl;

  if (ar.getSize( ) == ar3.getSize( ))  // Check sizes of arrays first
    ar2 = ar + ar3;    // Illegal addition, if size mismatch

  return 0;
}



/*    OUTPUT: arith4.cpp

	ar2[0] = 0
	ar2[1] = 11
	ar2[2] = 22
	ar2[3] = 33
	ar2[4] = 44

*/
