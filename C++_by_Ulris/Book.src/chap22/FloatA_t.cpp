// FloatA_t.cpp: 
// Testing the class FloatVek.
// -----------------------------------------------------

#include "floatArr.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   FloatArr v(10);        // Array v of 10 float values
   FloatArr w(20, 1.0F);  // To initialize an array w of
                          // 20 float values by 1.0.
   v.append( 0.5F);
   cout << " Current number of elements in v: " 
        << v.length() << endl;                 //   1
   cout << " Current number of elements in w: " 
        << w.length() << endl;                 //  20
   
   float x = -2.0F; 
   
   for( ; x < 2 ; x += 0.7F)
      v.append(x);

   cout << "\nThe elements of v after appending:"
        << endl;
   int i;                 // An index.
   for(i=0; i < v.length(); i++)
       cout << setw(6) << v[i];
   cout << endl;
   
   w.remove(3);           // Delete element in position 3.
   w.append(10.0F);       // To add a new element.
   if( !w.append(20.0F))  // And once again!
       cerr << "\nThe array w is filled!" << endl;

   for(i=0; i < w.length(); i++)
       cout << setw(4) << w[i];
   cout << endl;

   const FloatArr cv(v);        // Create a const object
                                // by the copy constructor.
   cout << "\nThe copy of v has been created.\n";
   cout << "\nThe arry elements of the copy:" << endl;
   for(i=0; i < cv.length(); i++)
       cout << setw(6) << cv[i];
   cout << endl;

   v = w;
   cout << "\nAssignment done.\n";
   cout << "\nThe elements after assignment:"
        << endl;
   
   for(i=0; i < v.length(); i++)
       cout << setw(4) << v[i];
   cout << endl;

   return 0;
}
