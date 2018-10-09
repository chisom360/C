// ---------------------------------------------------------
// sieve.cpp 
// Identifies prime numbers using the Sieve of Eratosthenes.
// ---------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

#define LIMIT  1000                   // Upper limit

bool flags[LIMIT] = { false, false};  // Array with flags

int main()
{
   register int i, j;                 // Indices

   for( i = 2; i < LIMIT; ++i)
       flags[i] = true;               // Sets flags to true
   
   // Sieving:
   for( i = 2; i < LIMIT/2; ++i)
   {
      if( flags[i])             // Is i a prime number?
      {                         // Yes -> Delete multiples.
         for( j = i+i; j < LIMIT; j += i)
            flags[j] = false;
      }
   }
 
   // To count:
   int count = 0;               // Counter 
   
   for( i = 2; i < LIMIT; ++i)
      if(flags[i])              // If i is a prime number
        ++count;                // -> count
   
   // Output:
   cout << "There are "<< count <<" prime numbers less than "
        << LIMIT << endl;
   
   cout << "\nTo output prime numbers? (y/n) ";
   
   char reply;  cin.get(reply);
   
   if( reply == 'y' || reply == 'Y')
   {
     for( i = 2; i < LIMIT; ++i)
        if(flags[i])            // If i is a prime number
        {                       // -> to output it.
           cout.width(8);  cout << i;
        }
   }
   
   cout << endl;
   
   return 0;
}
