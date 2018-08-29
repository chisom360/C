/*     FILE: name5.cpp     */


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
  using setOne::j;
  
  cout << "\n In func( ) j = " << j << endl;
  j += 5;
  cout << " Then in func( ) j = " << j << endl;
    
  return ;  
}

int main( )
{
  using setTwo::j;
  
  
  cout << " In main( ) j = " << j << endl;
  
  func( );
  
  cout << "\n Then in main( ) j = " << j << endl;
  
  func( );
  
  int j = 7;
  cout << "\n Finally in main( ) j = " << j << endl;
  cout << "\n Also finally in main( ) j = " << setOne::j << endl;
    
  return 0; 
}


/*    OUTPUT: name5.cpp

	name5.cpp: In function `int main()':
	name5.cpp:41: redeclaration of `int j'
	name5.cpp:13: `int setTwo::j' previously declared here
	name5.cpp:41: declaration of `int j'
	name5.cpp:13: conflicts with previous declaration `int setTwo::j'

*/
