// -------------------------------------------------------
// sort_t.cpp
// Compares the performances of sorting algorithms  
//            quick sort  and  selection sort 
// For this purpose, two identical arrays are dynamically
// generated and initialized with random numbers. 
// The times needed for sorting are displayed.
// -------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void isort(int *v, int lenv);

// For qsort():
extern "C" int intcmp(const void*, const void*);

main()
{
   unsigned int  i, size;
   int  *numbers1, *numbers2;
   long time1, time2;

   cout << "\n   The performance of the sorting algorithms"
        << "\n        quick sort  and  selection sort"
        << "\n    is being compared.\n\n"
        << "\nHow many numbers are to be sorted?   ";

   cin >> size;
   numbers1 = new int[size];
   numbers2 = new int[size];

   cout << "\nThere are "
        << size << " random numbers to be generated.\n";
   srand((unsigned)time(NULL)); // Initialize the 
                                // random number generator.  
   for(i = 0 ; i < size ; ++i)
      numbers1[i] = numbers2[i] = rand(); // Random numbers

   cout << "\nSorting starts! Please wait.\n";
   time(&time1);                     // Length of time 
                                     // for quick sort.  
   qsort(numbers1, size, sizeof(int), intcmp); 
   time(&time2);

   cout  << "\nTime taken by the quick sort algorithm: "
         <<   time2 - time1 << " seconds.\n";
 
   cout << "\nI am sorting again. Please wait!\n";

   time(&time1);                      // Length of time 
   isort(numbers2, size);             // for selection sort 
   time(&time2);

   cout << "\nTime taken by the insertion sort algorithm: "
        << time2 - time1 << " seconds.\n"
        << "\nOutput sorted numbers? (y/n)\n\n";

   char c;  cin >> c;
   if( c == 'Y' || c == 'y')
     for( i = 0 ; i < size ; ++i)
       cout << setw(10) <<  numbers1[i];

   cout << endl;
   return 0;
}


extern "C" int intcmp( const void *a, const void *b)
{
   return (*(int*)a - *(int*)b);
}

// -------------------------------------------------------
// isort()  sorts an array of int values 
//          using the selection sort algorithm. 

void isort( int *a, int len)   // Sort the array a of 
{                              // length len in ascending 
   register int *b, *minp;     // order
   int *last, help;

   last = a + len - 1;      // Points to the last element

   for( ; a <= last; ++a)   // Search for the smallest 
   {                        // element starting at a.
      minp = a;             // minp points to the "current" 
                            // smallest array element.  
      for( b = a+1; b <= last; ++b)    // Search for the 
         if( *b < *minp )              // minimum. 
             minp = b;

      help = *a, *a = *minp, *minp = help;    // Swap. 
   }
}
