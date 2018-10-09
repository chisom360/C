// list_t.cpp:  Tests list operations
// ----------------------------------------------------
#include <list>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef list<int>  INTLIST;

int display( const INTLIST& c);

int main()
{
  INTLIST ls, sls;

  for( int i=1; i<=3; i++)
    ls.push_back( rand()%10 );          // ex. 1 7 4

  cout << "The first list ls: " << endl;
  display(ls);               

  ls.push_back(ls.front());             // 1 7 4 1
  cout << "The first element has been appended:" << endl;
  display(ls);  

  ls.reverse();                         // 1 4 7 1
  cout << "The inverted list:" << endl;
  display(ls);

  ls.sort();                            // 1 1 4 7
  cout << "The sorted list:" << endl;
  display(ls);
  
  for( i=1; i<=3; i++)
    sls.push_back( rand()%10 );         // ex. 0 9 4
  cout << "A new list sls:" << endl; display(sls);

  // Insert the first object of sls before the last of ls:
  INTLIST::iterator pos = ls.end();
  
  ls.splice(--pos, sls, sls.begin());   // 1 1 4 0 7
  cout << "The first element of sls has been inserted before the last element of ls:" << endl; 
  display(ls); 
  cout << "The changed list sls:" << endl; 

  display(sls);                        // 9 4

  ls.sort();                           // 0 1 1 4 7 
  sls.sort();                          // 4 9
  ls.merge(sls);                       // 0 1 1 4  4 7 9

  cout << "Sorting and merging both lists:" << endl; 
  display(ls);         
  
  ls.unique();                         // 0 1 4 7 9
  cout << "Equivalent objects have been removed:" << endl; 
  display(ls);         
  
  return 0;
}


int display(const INTLIST& c)
{
   int z = 0;                             // Counter
   INTLIST::const_iterator pos;           // Iterator

   for( pos = c.begin(); pos != c.end(); pos++, z++)
     cout << *pos << "  ";
   cout << endl;
   cin.get();

   return z;
}
