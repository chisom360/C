// scope.cpp
// Accessing objects with equal names
// --------------------------------------------------- 

#include <iostream>
#include <iomanip>
using namespace std;

int var = 0;

namespace Special {  int var = 100; }

int main()
{
   int var = 10;
   cout << setw(10) << var;                   // 1.
   {  
      int var = 20;
      cout << setw(10) << var << endl;        // 2. 
      {
        ++var;
        cout << setw(10) << var;              // 3.
        cout << setw(10) << ++ ::var;         // 4.
        cout << setw(10) << Special::var * 2  // 5.
             << endl;
     }
      cout << setw(10) << var - ::var;        // 6.
   }
   cout << setw(10) << var << endl;           // 7.

   return 0;
}
