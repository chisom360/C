/*     FILE: FileBin.cpp     */

// Writing the binary representation of some floats

#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;
using std::cout;
using std::endl;

int main( )
{
  ofstream outs("tmp.out", ios::binary);
//  ofstream outs("tmp.out");

  float array[5] = {1.1,2.2,3.3,4.4,5.5};

  outs.write((char *)array, sizeof(array));

  outs.flush( );
  outs.close( );

  ifstream inp("tmp.out", ios::binary);
//  ifstream inp("tmp.out");

  float array2[5] = {0,0,0,0,0};

  inp.read((char *)array2, sizeof(array2));
  for(int j=0; j< 5; j++)
    cout << "array2[" << j << "] = "
         << array2[j] << endl;

  inp.close( );

}


/*    OUTPUT: FileBin.cpp

	array2[0] = 1.1
	array2[1] = 2.2
	array2[2] = 3.3
	array2[3] = 4.4
	array2[4] = 5.5

*/
