/*     FILE: Queue.cpp     */

// There are Queue containers. An iterator can be used to process the
// ... elements in a deque.

#include <iostream>
#include <deque>

using std::cout;
using std::endl;
using std::ostream;
using std::deque;

class MyDouble{
    double d;
  public:
    MyDouble(double param)
    { d = param;}
    double getDouble( )
    { return d;}
    bool operator<(const MyDouble & param) const
    { return d < param.d; }
           
    friend ostream& operator<<(ostream &os, const MyDouble & d);
};

ostream& operator<<(ostream &os, const MyDouble & d)
{
  os << d.d;

  return os;
}

void display(deque<MyDouble>::iterator start, deque<MyDouble>::iterator end)
{
  deque<MyDouble>::iterator iter;
  
  for(iter=start; iter != end; iter++)
     cout << *iter << endl;
    
  return;
}


int main( )
{
  int i;
  deque<MyDouble> MyDouble_queue;
  
  for(i=0; i<5; i++)   // load queue
     MyDouble_queue.push_back(MyDouble(i*1.1));

  cout << "Queue displayed: " << endl;
  display(MyDouble_queue.begin( ),MyDouble_queue.end( ));   // display queue
     
  for(i=0; i<2; i++){   // remove from queue
     cout << "Removing: " << MyDouble_queue.front( ) << endl;
     MyDouble_queue.pop_front( );
  }

  cout << "Queue displayed: " << endl;
  display(MyDouble_queue.begin( ),MyDouble_queue.end( ));   // display queue
     
  for(i=5; i<7; i++){   // add to the queue
     MyDouble_queue.push_back(MyDouble(i*1.1));
  }

  cout << "Queue displayed: " << endl;
  display(MyDouble_queue.begin( ),MyDouble_queue.end( ));   // display queue
     
  return 0;
}



/*    OUTPUT: Queue.cpp

	Queue displayed: 
	0
	1.1
	2.2
	3.3
	4.4
	Removing: 0
	Removing: 1.1
	Queue displayed: 
	2.2
	3.3
	4.4
	Queue displayed: 
	2.2
	3.3
	4.4
	5.5
	6.6

*/
