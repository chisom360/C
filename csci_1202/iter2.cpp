/*     FILE: iter2.cpp     */

// Uses a reverse iterator to process all the elements
// ... in reverse order.
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

  cout << "Vector reverse iterated: " << endl;
  vector<MyDouble>::reverse_iterator iter2;    // request an iterator from vector
  for(iter2 = v.rbegin( ); iter2 != v.rend( ); iter2++)   // display vector
     cout << *iter2 << endl;

  return 0;
}



/*    OUTPUT: iter2.cpp

	Vector iterated: 
	0
	1.1
	2.2
	3.3
	4.4
	Vector reverse iterated: 
	4.4
	3.3
	2.2
	1.1
	0

*/
