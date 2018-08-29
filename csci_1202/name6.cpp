/*     FILE: name6.cpp     */


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
  
  cout << "\n Finally in main( ) j = " << j << endl;
  cout << "\n Also finally in main( ) j = " << setOne::j << endl;
    
  return 0; 
}


/*    OUTPUT: name6.cpp

	 In main() j = 2
	
	 In func() j = 1
	 Then in func() j = 6
	
	 Then in main() j = 2
	
	 In func() j = 6
	 Then in func() j = 11
	
	 Finally in main() j = 2
	
	 Also finally in main() j = 11

*/
