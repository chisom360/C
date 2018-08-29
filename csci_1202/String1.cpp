/*     FILE: String1.cpp     */

// C++ has a class "string" that provides many
// ... features a C string doesn't.
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main( )
{
  string s = "Hello World.";      // It can act like a C string
  
  cout << "string s: " << s << endl;

  return 0;
}



/*    OUTPUT: String1.cpp

	string s: Hello World.

*/
