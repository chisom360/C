/*     FILE: mult4.cpp     */

#include <iostream>
using std::cout;
using std::endl;

#include "combov_array.h"

int main( )
{
  combo_array ar(5);
  combo_array ar2(5);
  combo_array ar3(7,12);

  for(int i=ar.getMinIndex( ); i<ar.getMaxIndex( ); i++)
    ar[i] = i;

  for(int i=ar2.getMinIndex( ); i<ar2.getMaxIndex( ); i++)
    ar2[i] = i*10;

  for(int i=ar3.getMinIndex( ); i<ar3.getMaxIndex( ); i++)
    ar3[i] = -i;

  for(int i=ar.getMinIndex( ); i<ar.getMaxIndex( ); i++)   // display array ar
    cout << "ar[" << i << "] = " << ar[i] << endl;

  cout << endl;
  for(int i=ar2.getMinIndex( ); i<ar2.getMaxIndex( ); i++)   // display array ar2
    cout << "ar2[" << i << "] = " << ar2[i] << endl;

  cout << endl;
  for(int i=ar3.getMinIndex( ); i<ar3.getMaxIndex( ); i++)   // display array ar3
    cout << "ar3[" << i << "] = " << ar3[i] << endl;

  ar3 = ar + ar2;

  cout << endl;
  for(int i=ar3.getMinIndex( ); i<ar3.getMaxIndex( ); i++)   // display array ar3
    cout << "ar3[" << i << "] = " << ar3[i] << endl;

  return 0;
}



/*    OUTPUT: mult4.cpp

	ar[0] = 0
	ar[1] = 1
	ar[2] = 2
	ar[3] = 3
	ar[4] = 4
	
	ar2[0] = 0
	ar2[1] = 10
	ar2[2] = 20
	ar2[3] = 30
	ar2[4] = 40
	
	ar3[7] = -7
	ar3[8] = -8
	ar3[9] = -9
	ar3[10] = -10
	ar3[11] = -11
	ar3[12] = -12
	
	ar3[0] = 0
	ar3[1] = 11
	ar3[2] = 22
	ar3[3] = 33
	ar3[4] = 44

*/
