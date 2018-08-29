/*     FILE: FileBin2.cpp     */

// Why ios::binary in some cases? Look at the size of the output file.

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

//  ifstream inp("tmp.out", ios::binary);
  ifstream inp("tmp.out");

  int array2[5] = {0,0,0,0,0};

  inp.read((char *)array2, sizeof(array2));
  for(int j=0; j< 5; j++)
    cout << "array2[" << j << "] = "
         << hex
         << array2[j] 
         << dec << endl;

  inp.close( );

}


/*    OUTPUT: FileBin2.cpp

	array2[0] = 1020304
	array2[1] = 5060708
	array2[2] = 90a0b0c
	array2[3] = d0e0f10
	array2[4] = 11121314

*/
