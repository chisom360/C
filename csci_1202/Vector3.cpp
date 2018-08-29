/*     FILE: Vector3.cpp     */

// The vector class will work with any data type.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::vector;

class MyDouble{
    double d;
  public:
    MyDouble(double param)
    { d = param;}
    double getDouble( )
    { return d;}
    
    friend ostream& operator<<(ostream &os, const MyDouble & d);
};

ostream& operator<<(ostream &os, const MyDouble & d)
{
  os << d.d ;

  return os;
}


int main( )
{
  int i;
  vector<MyDouble> MyDouble_vect;
  
  for(i=0; i<5; i++)   // load vector
     MyDouble_vect.push_back(MyDouble(i*1.1));

  cout << "Vector displayed: " << endl;
  for(i=0; i<MyDouble_vect.size( ); i++)   // display vector
     cout << MyDouble_vect[i] << endl;

  return 0;
}



/*    OUTPUT: Vector3.cpp

	Vector displayed: 
	0
	1.1
	2.2
	3.3
	4.4

*/
