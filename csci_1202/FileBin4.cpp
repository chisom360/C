/*     FILE: FileBin4.cpp     */

// Let's look a little closer.

#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::ios;
using std::hex;
using std::dec;
using std::cout;
using std::endl;

int main( )
{
//  ofstream outs("tmp.out", ios::binary);
  ofstream outs("tmp.out");

  int array[5] = {0x01020304,0x05060708,0x090a0b0c,0x0d0e0f10,0x11121314};

  outs.write((char *)array, sizeof(array));

  outs.close( );

  ifstream inp("tmp.out", ios::binary);
  //ifstream inp("tmp.out");

  char array2[21] = {0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0};

  inp.read((char *)array2, sizeof(array2));
  for(int j=0; j< 21; j++)
    cout << "array2[" << j << "] = "
         << hex
         << (int)array2[j] 
         << dec << endl;

  inp.close( );

}


/*    OUTPUT: FileBin4.cpp

	array2[0] = 4
	array2[1] = 3
	array2[2] = 2
	array2[3] = 1
	array2[4] = 8
	array2[5] = 7
	array2[6] = 6
	array2[7] = 5
	array2[8] = c
	array2[9] = b
	array2[10] = d
	array2[11] = a
	array2[12] = 9
	array2[13] = 10
	array2[14] = f
	array2[15] = e
	array2[16] = d
	array2[17] = 14
	array2[18] = 13
	array2[19] = 12
	array2[20] = 11

*/
