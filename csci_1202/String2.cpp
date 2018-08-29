/*     FILE: String2.cpp     */

// C++ has a class "string" that provides many
// ... features a C string doesn't.
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main( )
{
  string s;

  s = "Hello";    // Assignment  
  cout << "string s: " << s << endl;
  
  s = s + " World.";    // concatentation with '+'  
  cout << "string s: " << s << endl;

  string s2 = s;        // copy constructor/duplication
  cout << "string s2: " << s2 << endl;

  // search functions
  cout << "\nFound: " << s.find("Wor") << endl;

  // substring functions
  cout << "\nFound: " << s.substr(s.find("Wor"),s.size( )) << endl;
  cout << "Found: " << s2.substr(s2.find("Wor"),s2.size( )) << endl;

  return 0;
}



/*    OUTPUT: String2.cpp

	string s: Hello
	string s: Hello World.
	string s2: Hello World.
	
	Found: 6
	
	Found: World.
	Found: World.

*/
