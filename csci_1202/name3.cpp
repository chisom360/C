/*     FILE: name3.cpp     */

/*
   Names can be selectively drawn out of a namespace into the local namespace
*/

#include <iostream>
using std::cout;
using std::endl;

int main( )
{
  int j = 7;
  
  cout << " In main( ) j = " << j << endl;
  
  j++;
  
  cout << "\n Finally in main( ) j = " << j << endl;
    
	return 0;	
}


/*    OUTPUT: name3.cpp

	 In main() j = 7
	
	 Finally in main() j = 8

*/
