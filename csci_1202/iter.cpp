/*     FILE: iter.cpp     */

// Uses an iterator to process all the elements
// ... in the vector.
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
    int operator<(const MyDouble & param) const
    { return d < param.d; }
           
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
  vector<MyDouble> v;
  
  for(i=0; i<5; i++)   // load vector
     v.push_back(MyDouble(i*1.1));

  cout << "Vector iterated: " << endl;
  vector<MyDouble>::const_iterator iter1;    // request an iterator from vector
  for(iter1 = v.begin( ); iter1 != v.end( ); iter1++)   // display vector
     cout << *iter1 << endl;

  return 0;
}



/*    OUTPUT: iter.cpp

	Vector iterated: 
	0
	1.1
	2.2
	3.3
	4.4

*/
