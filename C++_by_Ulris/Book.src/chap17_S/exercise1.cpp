// exercise1.cpp
// Testing arithmetic with pointers.
// ----------------------------------------------------

#include <iostream>
using namespace std;

int main( )
{
   int v[] = { 10, 20, 30, 40 },
       i, *pv;

   // What is shown on the display by the following statements?

   cout << "a)\n";
   for( pv = v;  pv <= v + 3;  pv++ )
     cout << "      *pv = "  <<  *pv;
   cout << endl;
   
   cout << "b)\n";
   for( pv = v, i = 1;  i <= 3;  i++ )
     cout << "    pv[i] = "  <<  pv[i];
   cout << endl;

   cout << "c)\n";
   for( pv = v, i = 0;  pv + i <= &v[3];  pv++,i++)
     cout << "  *(pv+i) = "  <<  *(pv + i);
   cout << endl;

   cout << "d)\n";
   for( pv = v + 3;  pv >= v;  pv-- )
     cout << "     v["  <<  (pv - v)  <<  "] = "
          << v[pv - v];

   cout << endl;

   return 0;
}
