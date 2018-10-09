// ---------------------------------------------------
// bubble.cpp 
// Inputs integers into an array,
// sorts in ascending order, and outputs them.
// ---------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX  100                     // Maximum number
long number[MAX];

int main()
{
   int i, cnt;                       // Index, quantity

   cout << "\nS o r t i n g  I n t e g e r s \n"
        << endl;

   // To input the integers:
   cout << "Enter up to 100 integers \n"
        << "(Quit with any letter):" << endl;
   for( i = 0; i < MAX  &&  cin >> number[i]; ++i)
       ;
   cnt = i;

   // To sort the numbers:
   bool sorted = false;              // Not yet sorted. 
   long help;                        // Swap.
   int  end = cnt;                   // End of a loop.

   while( !sorted)                   // As long as not
   {                                 // yet sorted.
     sorted = true;
     --end;
     for( i = 0; i < end; ++i)       // Compares 
     {                               // adjacent integers.
       if( number[i] > number[i+1])
       {
          sorted = false;            // Not yet sorted.
          help       = number[i];    // Swap.
          number[i]  = number[i+1];
          number[i+1]= help;
       }
     }
   }
 
   // Outputs the numbers
   cout << "The sorted numbers:\n" << endl;

   for( i = 0; i < cnt; ++i)
      cout << setw(10) << number[i];
   cout << endl;

   return 0;
}
