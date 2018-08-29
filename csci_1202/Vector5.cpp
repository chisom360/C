/*     FILE: Vector5.cpp     */

// The vector class will work with any data type.

// There are standard algorithms that work with the 
// ... container classes.

// The sort order produced by operator< can be 
// ... overridden in the call to sort( )

#include <iostream>
#include <vector>
#include <algorithm>

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
    bool operator<(const MyDouble & param) const
    { return d < param.d; }
    bool operator>(const MyDouble & param) const
    { return d > param.d; }
           
    friend ostream& operator<<(ostream &os, const MyDouble & d);
};

ostream& operator<<(ostream &os, const MyDouble & d)
{
  os << d.d ;

  return os;
}

bool descending(const MyDouble & d1, const MyDouble & d2)
{
  return d1>d2;
}


int main( )
{
  int i;
  vector<MyDouble> MyDouble_vect;
  
  for(i=5; i>0; i--)   // load vector
     MyDouble_vect.push_back(MyDouble(i*1.1));

  cout << "Vector displayed: " << endl;
  for(i=0; i<MyDouble_vect.size( ); i++)   // display vector
     cout << MyDouble_vect[i] << endl;

/***  sort vector v  ****/
  sort(MyDouble_vect.begin( ), MyDouble_vect.end( ));
  
  cout << "Vector displayed: " << endl;
  for(i=0; i<MyDouble_vect.size( ); i++)   // display vector
     cout << MyDouble_vect[i] << endl;
     
/***  sort vector v  ****/
  sort(MyDouble_vect.begin( ), MyDouble_vect.end( ), descending);
  
  cout << "Vector displayed: " << endl;
  for(i=0; i<MyDouble_vect.size( ); i++)   // display vector
     cout << MyDouble_vect[i] << endl;
     
  return 0;
}



/*    OUTPUT: Vector5.cpp

	Vector displayed: 
	5.5
	4.4
	3.3
	2.2
	1.1
	Vector displayed: 
	1.1
	2.2
	3.3
	4.4
	5.5
	Vector displayed: 
	5.5
	4.4
	3.3
	2.2
	1.1

*/
