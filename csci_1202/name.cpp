/*     FILE: name.cpp     */

/*
   Namespaces allow for separating identifiers within a C++ program
   according to the programmers design.
   
   The namespace std contains the Standard C++ definitions.
*/

#include <iostream>
//using namespace std;

int main( )
{
  int j = 7;
  
  cout << " In main( ) j = " << j << endl;
  
  j++;
  
  cout << "\n Finally in main( ) j = " << j << endl;
    
	return 0;	
}


/*    OUTPUT: name.cpp

	name.cpp: In function `int main()':
	name.cpp:15: `cout' undeclared (first use this function)
	name.cpp:15: (Each undeclared identifier is reported only once for each 
	   function it appears in.)
	name.cpp:15: `endl' undeclared (first use this function)

*/
