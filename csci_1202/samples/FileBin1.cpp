/*     FILE: FileBin1.cpp     */

// Writing the binary representation of some floats

#include <iostream>
#include <fstream>

using std::ifstream;
using std::ios;
using std::cout;
using std::endl;

int main(int argc, char * argv[] )
{
  if(argc > 1)
  {
    ifstream inp(argv[1], ios::binary);
    //  ifstream inp("tmp.out");

    int i;

    inp.read((char *)&i, sizeof(int));
    cout << "Integer: " << i << endl;

    inp.close( );
  }
}

