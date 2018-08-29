/*     FILE: name2.cpp     */

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
  
  std::cout << " In main( ) j = " << j << std::endl;
  
  j++;
  
  std::cout << "\n Finally in main( ) j = " << j << std::endl;
    
	return 0;	
}


/*    OUTPUT: name2.cpp

	 In main() j = 7
	
	 Finally in main() j = 8

*/
