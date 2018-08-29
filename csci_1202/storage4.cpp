/*     FILE: storage4.cpp     */

/*
   Externals are of program scope and duration.
   - initialized once, to zero by default.
*/

#include <iostream>
using namespace std;

int j;

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
  
  cout << "\n Finally in main( ) j = " << j << endl;
    
	return 0;	
}


/*    OUTPUT: storage4.cpp

	 In main() j = 0
	
	 In func() j = 0
	 Then in func() j = 5
	
	 Then in main() j = 5
	
	 In func() j = 5
	 Then in func() j = 10
	
	 Finally in main() j = 10

*/
