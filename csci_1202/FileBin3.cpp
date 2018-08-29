/*     FILE: FileBin3.cpp     */

// Why ios::binary in some cases? Let's look and see.

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

  char array[20] = {0x01,0x02,0x03,0x04,0x05,
                    0x06,0x07,0x08,0x09,0x0a,
                    0x0b,0x0c,0x0d,0x0e,0x0f,
                    0x10,0x11,0x12,0x13,0x14};

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


/*    OUTPUT: FileBin3.cpp

	array2[0] = 1
	array2[1] = 2
	array2[2] = 3
	array2[3] = 4
	array2[4] = 5
	array2[5] = 6
	array2[6] = 7
	array2[7] = 8
	array2[8] = 9
	array2[9] = d
	array2[10] = a
	array2[11] = b
	array2[12] = c
	array2[13] = d
	array2[14] = e
	array2[15] = f
	array2[16] = 10
	array2[17] = 11
	array2[18] = 12
	array2[19] = 13
	array2[20] = 14

*/
