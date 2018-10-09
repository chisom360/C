// DynArr.cpp 
// Operators new[] and delete[] for dynamic arrays.
// ----------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   cout << "Using a dynamic array.\n" << endl;

   int size = 0, cnt = 0, step = 10,
       i;
   float x, *pArr = NULL;

   cout << "Enter some numbers!\n"
           "End with q or another character " << endl;
   while( cin >> x)
   {
     if( cnt >= size)             // Array too small?
     {                            // => enlarge it.
        float *p = new float[size+step];
                                  // Copy the numbers:
        for( i = 0; i < size; ++i)
           p[i] = pArr[i];
        delete [] pArr;           // Release old array
        pArr = p;  size += step;
     }
     pArr[cnt++] = x;
   }

   // Work with the numbers:
   if( cnt == 0)
     cout << "No invalid input!" << endl;
   else
   {
     float sum = 0.0;
     cout << "Your input: " << endl;
     for( i = 0; i < cnt; i++)       // To output and
     {                               // add.
       cout << setw(10) << pArr[i];
       sum += pArr[i];
     }
     cout << "\nThe average: " << sum/cnt << endl;
   }

   delete [] pArr;                // Release memory

   return 0;
}
