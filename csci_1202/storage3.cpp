/*     FILE: storage3.cpp     */

/*
   Static automatic gives program duration but function scope. 
   Statics are initialized once, to zero by default. Low/no overhead
*/

#include <iostream>
using namespace std;

void func( )
{
	static int j;
	
	cout << "\n In func( ) j = " << j << endl;
	j += 5;
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


/*    OUTPUT: storage3.cpp

	 In main() j = 7
	
	 In func() j = 0
	 Then in func() j = 5
	
	 Then in main() j = 7
	
	 Stirring the pot.
	
	 In func() j = 5
	 Then in func() j = 10
	
	 Finally in main() j = 7

*/
