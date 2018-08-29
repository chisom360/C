/*     FILE: File4.cpp     */

// Using C++ manipulators to manipulate an output stream

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::dec;
using std::oct;
using std::hex;

int main( )
{
  int val = 75;

  cout << val << " in decimal =  " << val << endl;
  cout << dec << val << " in octal =  " << oct << val << endl;
  cout << dec << val << " in hexadecimal =  " << hex << val << endl;

}


/*    OUTPUT: File4.cpp

	75 in decimal =  75
	75 in octal =  113
	75 in hexadecimal =  4b

*/
