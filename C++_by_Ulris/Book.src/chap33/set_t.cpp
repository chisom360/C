// ----------------------------------------------------
// set_t.cpp:  Tests Sets and Multisets
// ----------------------------------------------------

#include <set>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

typedef set<int> IntSet;             // Define type and 
typedef IntSet::iterator SetIter;    // iterator type 

typedef multiset<int> IntMultiSet;   // Multiset and 
typedef IntMultiSet::iterator MultiSetIter;  // iterator

int main()
{
   IntSet  lotto;               // To create a set.
   SetIter pos;                 // Bidirectional iterator 

   srand((unsigned) time(NULL));
   while( lotto.size() < 6)     // Insert
     lotto.insert( 1 + rand()%49 );      
   
   cout << "These are your lotto numbers: " << endl;
   for( pos = lotto.begin(); pos != lotto.end(); pos++)
       cout << *pos << "  ";
   cout << endl << endl;
   
   IntMultiSet  ms;             // Create a multiset. 
   MultiSetIter mpos;           // Bidirectional iterator 

   for( int i=0; i < 10; i++)   // Insert
     ms.insert( rand()%10 );      
   
   cout << "And now 10 random numbers "
        << "between  0 and 9: " << endl;
   for( mpos = ms.begin(); mpos != ms.end(); mpos++)
       cout << *mpos << "  ";
   cout << endl;

   return 0;
}

