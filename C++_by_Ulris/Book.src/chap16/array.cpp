// array.cpp 
// To input numbers into an array and output after.
// ----------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   const int MAXCNT = 10;       // Constant
   float arr[MAXCNT], x;        // Array, temp. variable
   int i, cnt;                  // Index, quantity

   cout << "Enter up to 10 numbers \n"
        << "(Quit with a letter):" << endl;
   for( i = 0; i < MAXCNT  &&  cin >> x; ++i)
      arr[i] = x;
   cnt = i;

   cout << "The given numbers:\n" << endl;
   for( i = 0; i < cnt; ++i)
      cout << setw(10) << arr[i];
   cout << endl;
   return 0;
}

/*
// array.cpp 
// To input numbers into an array and compute 
// the average and deviation of average.
// ---------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   const int MAXCNT = 10;            // Constant
   float arr[MAXCNT], x, average;     
   int i, cnt;                       // Index, quantity

   // To input numbers:
   cout << "Input up to 10 numbers\n"
        << "(Quit by a letter):" << endl;
   for( i = 0; i < MAXCNT  &&  cin >> x; ++i)
      arr[i] = x;
   cnt = i;

   if( cnt == 0)
   {
      cout << "Invalid input!" << endl;
      return 1;
   }

   // Computing the average
   for( average = 0.0, i = 0; i < cnt; ++i)
       average += arr[i];
   average /= cnt;

   // Output:
   cout << "The average: " << average << endl;

   cout << "The deviation of average:" << endl;
   for( i = 0; i < cnt; ++i)
      cout << setw(8) << arr[i] - average;
   cout << endl;

   return 0;
}
*/
