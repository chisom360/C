// -------------------------------------------------------
// selSort.cpp
// Implement the selection sort algorithm for int-arrays.
// -------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>           // For srand(), rand()
#include <ctime>             // For time()
using namespace std;

// Prototype:
void selectionSort( int arr[], int len);

const int len = 200;

int intArr[len];             // int-array

int main()
{
   cout << "\n     ***  Selection Sort Algorithm  ***\n"
        << endl;

   // To initialize an int-array by random numbers:
   srand( (unsigned int)time(NULL));  // Initialize the 
                                      // random number generator.
   for( int n=0; n < len; ++n) 
       intArr[n] = (rand() % 20000)-10000;

   // To sort the numbers
   selectionSort( intArr, len);

   // To output the numbers
   cout << "The sorted numbers:" << endl;

   for( int i = 0; i < len; ++i)
      cout << setw(8) << intArr[i];
   cout << endl;

   return 0;
}

inline void swap( int& a, int& b)
{
   int temp = a;  a = b;  b = temp;
}

 
//  Index version:
/*
void selectionSort( int arr[], int len)
{
   register int j, mini;             // Indices

   for( int i = 0;  i < len-1;  ++i)
   {
      mini = i;                      // To search the minimum
      for( j = i+1; j < len; ++j)    // starting at index i.
         if( arr[mini] > arr[j])
             mini = j;

      swap( arr[i], arr[mini]);      // To swap.
   }
}
*/

// Zeiger-Version:
void selectionSort( int *arr, int len)
{
   register int *p, *minp;    // Pointer to array elements,
   int *last = arr + len-1;   // pointer to the last element

   for( ; arr < last;  ++arr)
   {
      minp = arr;                    // To search the minimum 
      for( p = arr+1; p<=last; ++p)  // starting with arr
         if( *minp > *p)
             minp = p;

      swap( *arr, *minp);            // To swap.
   }
}
