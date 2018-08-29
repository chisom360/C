/*     FILE: storage.cpp     */

/*
   Automatic storage is allocated when the function is called.
   - it is uninitialized. This allows for fast allocation
   - you get what you get, which can fool you 
*/

#include <iostream>
using namespace std;

void func( )
{
	int j;
	
	cout << "\n In func( ) j = " << j << endl;
	j = 5;
	cout << " Then in func( ) j = " << j << endl;
	  
	return ;	
}

int main( )
{
  int j = 7;
  
  cout << " In main( ) j = " << j << endl;
  
  func( );
	
  cout << "\n Then in main( ) j = " << j << endl;
  
  func( );
  
  cout << "\n Finally in main( ) j = " << j << endl;
    
	return 0;	
}


/*    OUTPUT: storage.cpp

	 In main() j = 7
	
	 In func() j = 4335816
	 Then in func() j = 5
	
	 Then in main() j = 7
	
	 In func() j = 4335816
	 Then in func() j = 5
	
	 Finally in main() j = 7

*/
