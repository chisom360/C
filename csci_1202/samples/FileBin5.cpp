/*     FILE: FileBin1.cpp     */

// Writing the binary representation of some floats

#include <iostream>
#include <fstream>

using std::ifstream;
using std::ios;
using std::cout;
using std::endl;

int bigToLittle(ifstream &inputStream);

int main(int argc, char * argv[] )
{
  int counter, number;
  
  if(argc > 1)
  {
    ifstream inp(argv[1], ios::binary);
    //  ifstream inp("tmp.out");

    number = bigToLittle(inp);
    cout << "Number: " << number << endl;
    
    for(counter=0; counter < number; counter++){
      cout << "Avenue: " << bigToLittle(inp);
      cout << "  Street: " << bigToLittle(inp) << endl;
    }
      
    
    inp.close( );
  }
}

int bigToLittle(ifstream &inputStream)
{
    char ar[4];
    int i;
    
    inputStream.read((char *)&ar, sizeof(int));
    
    i = 0;
    
    i += ar[0]<<24;
    i += ar[1]<<16;
    i += ar[2]<<8;
    i += ar[3];

    return i;
}

