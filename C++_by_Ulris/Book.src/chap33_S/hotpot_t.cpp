// ----------------------------------------------------- 
// hotpot_t.cpp : Simulates the hot potatoe algorithm 
//                using a vector of queues.
// ----------------------------------------------------- 

#include <cstdlib>       // For srand(), rand()
#include <ctime>         // For time()

#include <iostream>
#include <iomanip>
using namespace std;

#include "vecQueue.h"

int main()
{
   const int nQueues = 9;
   VecQueue<int> vq(nQueues);    // Vector of 9 queues
   
   cout << nQueues << " queues have been created."
        << endl;

   srand(time(NULL));

   cout << "\nThe queues will now be filled "
        << "using the hot potato algorithm."
        << endl;

   int i;
   for(i = 0; i < 100; i++)      // To insert 100 elements
     vq.push(rand()%100); 

   cout << "\nSome elements of randomly selected "
           "queues are removed." 
        << endl;

   for(i=0; i < 50; i++)         // To remove 50 elements
       vq.pop();

   cout << "\nTo output the queues:" << endl;
   for( i = 0; i < nQueues; ++i) // To retrieve, remove and display  
   {                             // all remaining elements
      cout << "\n" << i+1 << ".Queue: ";
      while( vq.size(i) > 0 )
      {
         cout << setw(4) << vq.pop(i);
      }
      cout << endl;
   }

   return 0;
}
