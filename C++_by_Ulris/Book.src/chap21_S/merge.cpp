// ----------------------------------------------------
// merge.cpp 
// Implements the merge algorithm.
// ----------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Prototypes:
void selectionSort( int arr[], int len);
int *merge( int v1[], int len1, int v2[], int len2);

int main()
{
    cout << "\n  * * *  The Merge Algorithm  * * *\n"
         << endl;

    int i, len1 = 10, len2 = 20;
    int *a1 = new int[len1],
        *a2 = new int[len2];

// Initialize the random number generator
// with the current time:
    srand( (unsigned)time(NULL));

    for( i=0; i < len1; ++i)   // Initialized arrays: 
       a1[i] = rand();
    for( i=0; i < len2; ++i) 
       a2[i] = rand();

    selectionSort( a1, len1);      // To sort array a1. 
    selectionSort( a2, len2);      // To sort array a2.

   // Output the arrays: 
   cout << "The sorted arrays:" << endl;
   cout << "1st array: " << endl;
   for( i = 0; i < len1; ++i)
      cout << setw(10) << a1[i];
   cout << endl;

   cout << "2nd array: " << endl;
   for( i = 0; i < len2; ++i)
      cout << setw(10) << a2[i];
   cout << endl;

   int *a3, len3; 
   a3   = merge( a1, len1, a2, len2);
   len3 = len1 + len2;
 
   cout << "The new merged array: " << endl;
   for( i = 0; i < len3; ++i)
      cout << setw(10) << a3[i];
   cout << endl;

   delete[] a1;   delete[] a2;   delete[] a3;

   return 0;
}

// ------------------------------------------------------
// Function selectionSort().
inline void swap( int& a, int& b)      // To swap.
{  int temp = a;  a = b;  b = temp; }

void selectionSort( int *arr, int len)
{
   register int *p, *minp;   // Pointer to array elements,
   int *last = arr + len-1;  // Pointer to the last element

   for( ; arr < last;  ++arr)
   {
      minp = arr;                      // Search minimum starting
      for( p = arr+1; p <= last; ++p)  // at position arr.
         if( *minp > *p)
             minp = p;
      swap( *arr, *minp);              // To swap.
   }
}

// ------------------------------------------------------
// merge() : Merges two sorted arrays to create 
//           a new sorted array.
int *merge( int v1[], int len1, int v2[], int len2)
{
   int i = 0, i1 = 0, i2 = 0;
   int *v = new int[len1+len2];    // New int array.

   for( i=0; i1 < len1 && i2 < len2; ++i) 
   {
       if( v1[i1] <= v2[i2])
           v[i] = v1[i1++];
       else
           v[i] = v2[i2++];
   }
   if( i1 < len1)        // Copy the rest of v1 or v2.
     while( i1 < len1)
       v[i++] = v1[i1++];
   else
     while( i2 < len2)
       v[i++] = v2[i2++];
   return v;
}
