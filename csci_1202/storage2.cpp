/*     FILE: storage2.cpp     */

/*
   Automatic storage is allocated when the function is called.
   - it is uninitialized which means it probably isn't zero 
     and certainly it isn't predictable
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

void stir( )
{
	double x,y,z;
	
	cout << "\n Stirring the pot." << endl;
	
	x = 5.5;
	y = 2.2;
	
	z = x*y;
	  
	return ;	
}

int main( )
{
  int j = 7;
  
  cout << " In main( ) j = " << j << endl;
  
  func( );
	
  cout << "\n Then in main( ) j = " << j << endl;
  
  stir( );
  func( );
  
  cout << "\n Finally in main( ) j = " << j << endl;
    
	return 0;	
}


/*    OUTPUT: storage2.cpp

	 In main() j = 7
	
	 In func() j = 4335928
	 Then in func() j = 5
	
	 Then in main() j = 7
	
	 Stirring the pot.
	
	 In func() j = 1075183616
	 Then in func() j = 5
	
	 Finally in main() j = 7

*/
