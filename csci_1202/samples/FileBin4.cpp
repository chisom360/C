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

    char ar[4];

    inp.read((char *)&ar, sizeof(int));
    
    cout << "ar[0]: " << (int)ar[0] << endl;
    cout << "ar[1]: " << (int)ar[1] << endl;
    cout << "ar[2]: " << (int)ar[2] << endl;
    cout << "ar[3]: " << (int)ar[3] << endl;
    
    int i;
    
    i = 0;
    
    i += ar[0]<<24;
    i += ar[1]<<16;
    i += ar[2]<<8;
    i += ar[3];

    cout << endl;
    cout << "Integer: " << i << endl;
    
    inp.close( );
  }
}

