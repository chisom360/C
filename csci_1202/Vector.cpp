/*     FILE: Vector.cpp     */

// C++ has a class vector that acts like an array 
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main( )
{
  int i;
  vector<int> v(5);
  
  for(i=0; i<5; i++)   // load vector
     v[i] = i;
                       // display vector
  cout << "Vector displayed: " << endl;
  for(i=0; i<5; i++)   
     cout << "v[" << i <<"] = " << v[i] << endl;

  return 0;
}



/*    OUTPUT: Vector.cpp

	Vector displayed: 
	v[0] = 0
	v[1] = 1
	v[2] = 2
	v[3] = 3
	v[4] = 4

*/
