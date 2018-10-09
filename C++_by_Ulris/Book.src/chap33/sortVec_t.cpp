// sortv_t.cpp :   Tests the template SortVec.
//---------------------------------------------------
#include "sortvec.h"
#include <iostream>
using namespace std;

typedef SortVec<int> IntSortVec;

int display(const IntSortVec& c);

int main()
{
   IntSortVec v, w;            // Default constructor

   v.insert(2);                 
   v.insert(7); 
   v.insert(1);

   display(v);

   int key;
   cout << "Key? " << endl;  cin >> key; 
   
   int n = v.search(key);         

   if( n > -1)
       cout << "Key " << key << " found!" << endl;
   else
       cout << "Key " << key << " not found!" << endl; 
   
   w.insert(3);  w.insert(9);
   cout << "\nA second array:\n";
   display(w);

   cout << "\nAnd merging the vectors: " << endl;

   v.merge(w);                  
   display(v);
   // The array v then contains the elements: 1 2 3 7 9

   return 0;
}


int display(const IntSortVec& c)
{
   int z = 0;                                // Counter
   SortVec<int>::const_iterator pos;         // Iterator

   for( pos = c.begin(); pos != c.end(); pos++, z++)
     cout << *pos << "  ";
   cout << endl;
   
   return z;
}
