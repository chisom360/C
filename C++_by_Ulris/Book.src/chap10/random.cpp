// random.cpp
// To generate and output random numbers.
//-----------------------------------------------------
#include <iostream>
#include <iomanip> 
#include <cstdlib>     // For rand(), srand()
#include <ctime>       // For time()
using namespace std;

bool setrand = false; 

inline void init_random()    // Initializes the random 
{                            // number generator with the 
                             // present time.
   if( !setrand )
   {  srand((unsigned int)time(NULL));
      setrand = true;
   }
}

inline double myRandom()     // Returns random number x
{                            // with  0.0 <= x <= 1.0
   init_random(); 
   return  (double)rand() / (double)RAND_MAX; 
}

inline int myRandom(int start, int end)  // Returns a
{                               // random number n with
   init_random();               // start <= n <= end
   return (rand() % (end+1 - start) + start); 
}

// Testing myRandom() and myRandom(int,int):
int main()
{
   int i;
   cout << "5 random numbers between 0.0 and 1.0 :"
        << endl;

   for( i = 0; i < 5; ++i)
      cout << setw(10) << myRandom();
   cout << endl;
   
   cout << "\nAnd now 5 integer random numbers "
           "between -100 and +100 :" << endl;  
   
   for( i = 0; i < 5; ++i)
      cout << setw(10) << myRandom(-100, +100);
   cout << endl; 
   
   return 0;
}
