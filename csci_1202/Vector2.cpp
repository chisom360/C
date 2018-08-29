/*     FILE: Vector2.cpp     */

// C++ has a class vector that acts like an array.

// A vector is dynamic.  It can expand and contract 
// ... as needed.
 
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main( )
{
  int i;
  vector<int> v(5);
  
  for(i=0; i<v.size( ); i++)   // load vector
     v[i] = i;
                       // display vector
  cout << "Vector displayed: " << endl;
  for(i=0; i<v.size( ); i++)   
     cout << "v[" << i <<"] = " << v[i] << endl;

  cout << "v's capacity = " << v.capacity( ) << endl;
  cout << "v's size = " << v.size( ) << endl;

  /***   Expand vector v  ****/
  for(i=0; i<4; i++)   // load vector
     v.push_back(5+i);
                       // display vector
  cout << "Vector displayed: " << endl;
  for(i=0; i<v.size( ); i++)   
     cout << "v[" << i <<"] = " << v[i] << endl;

  cout << "v's capacity = " << v.capacity( ) << endl;
  cout << "v's size = " << v.size( ) << endl;

  /***   Shrink vector v  ****/
  v.erase(v.end( )-3,v.end( ));
                       // display vector
  cout << "Vector displayed: " << endl;
  for(i=0; i<v.size( ); i++)   
     cout << "v[" << i <<"] = " << v[i] << endl;

  cout << "v's capacity = " << v.capacity( ) << endl;
  cout << "v's size = " << v.size( ) << endl;

  return 0;
}



/*    OUTPUT: Vector2.cpp

	Vector displayed: 
	v[0] = 0
	v[1] = 1
	v[2] = 2
	v[3] = 3
	v[4] = 4
	v's capacity = 5
	v's size = 5
	Vector displayed: 
	v[0] = 0
	v[1] = 1
	v[2] = 2
	v[3] = 3
	v[4] = 4
	v[5] = 5
	v[6] = 6
	v[7] = 7
	v[8] = 8
	v's capacity = 10
	v's size = 9
	Vector displayed: 
	v[0] = 0
	v[1] = 1
	v[2] = 2
	v[3] = 3
	v[4] = 4
	v[5] = 5
	v's capacity = 10
	v's size = 6

*/
