// -------------------------------------------
// mulmap_t.cpp:  Testing multimaps
// -------------------------------------------

#include <map>
#include <string>
#include <iostream>
using namespace std;

typedef multimap<int, string> MULTI_MAP;
typedef MULTI_MAP::iterator ITERATOR;

int main()
{
   MULTI_MAP  m;            // Create a multimap.
   ITERATOR pos;            // Iterator.
                            // To insert:   
   m.insert( pair<int, string>(7, "Bob") );        
   m.insert( pair<int, string>(3, "Sarah"));
   m.insert( pair<int, string>(1, "Diana"));
   m.insert( pair<int, string>(1, "Lisa"));

   cout << "This is the multimap: " << endl;
   for(pos = m.begin(); pos!= m.end(); pos++)
       cout << pos->first << "  "
            << pos->second << endl;      
   cout << endl;

   pos = m.find(3);       // Search for the pair 
                          // with given key 3
   if( pos != m.end())    // and output the pair
   {
     cout << "This is the pair with key 3: " << endl;
     cout << pos->first << "  " << pos->second << endl;
   }

   int key = 1;           // Determine the quantity of
                          // pairs with key value 1:
   cout << "There are " << m.count(key) 
        << " pairs with key " << key << endl;

   return 0;
}
