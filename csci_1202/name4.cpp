/*     FILE: name4.cpp     */

/*
   Namespaces create separate regions of scope and can be made accessible 
*/

#include <iostream>
using namespace std;

namespace setOne{
	
	int j=1;

}

namespace setTwo{
	
	int j=2;

}

void func( )
{
  
  cout << "\n In func( ) j = " << j << endl;
  j += 5;
  cout << " Then in func( ) j = " << j << endl;
    
  return ;  
}

int main( )
{
  
  cout << " In main( ) j = " << j << endl;
  
  func( );
  
  cout << "\n Then in main( ) j = " << j << endl;
  
  func( );
  
  int j = 7;
  cout << "\n Finally in main( ) j = " << j << endl;
  cout << "\n Also finally in main( ) j = " << ::j << endl;
    
  return 0; 
}


/*    OUTPUT: name4.cpp

	name4.cpp: In function `void func()':
	name4.cpp:23: `j' undeclared (first use this function)
	name4.cpp:23: (Each undeclared identifier is reported only once for each 
	   function it appears in.)

*/
