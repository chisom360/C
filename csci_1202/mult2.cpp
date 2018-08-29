/*     FILE: mult2.cpp     */

#include <iostream>
using std::cout;
using std::endl;

#include "index_array.h"

int main( )
{
  index_array ar(5);
  index_array ar2(-3,7);

  for(int i=ar.getMinIndex( ); i<ar.getMaxIndex( ); i++)
     ar[i] = i;

  for(int i=ar2.getMinIndex( ); i<ar2.getMaxIndex( ); i++)
     ar2[i] = i*10;

  for(int i=ar.getMinIndex( ); i<ar.getMaxIndex( ); i++)   // display array ar
     cout << "ar[" << i << "] = " << ar[i] << endl;

  cout << endl;
  for(int i=ar2.getMinIndex( ); i<ar2.getMaxIndex( ); i++)   // display array ar2
     cout << "ar2[" << i << "] = " << ar2[i] << endl;

  ar = ar2;

  cout << endl;
  for(int i=ar.getMinIndex( ); i<ar.getMaxIndex( ); i++)   // display array ar
     cout << "ar[" << i << "] = " << ar[i] << endl;      // ...after assignment

  return 0;
}


/*    OUTPUT: mult2.cpp

	ar[0] = 0
	ar[1] = 1
	ar[2] = 2
	ar[3] = 3
	ar[4] = 4
	
	ar2[-3] = -30
	ar2[-2] = -20
	ar2[-1] = -10
	ar2[0] = 0
	ar2[1] = 10
	ar2[2] = 20
	ar2[3] = 30
	ar2[4] = 40
	ar2[5] = 50
	ar2[6] = 60
	ar2[7] = 70
	
	ar[-3] = -30
	ar[-2] = -20
	ar[-1] = -10
	ar[0] = 0
	ar[1] = 10
	ar[2] = 20
	ar[3] = 30
	ar[4] = 40
	ar[5] = 50
	ar[6] = 60
	ar[7] = 70

*/
