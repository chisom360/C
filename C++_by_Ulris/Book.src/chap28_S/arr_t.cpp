// -------------------------------------------------------
// arr_h.cpp
// Tests exception handling for float arrays.
// -------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

#include "floatArr.h"

int main()
{
    const FloatArr v(10, 9.9f); 
    bool ok = false;

    while( !ok)
    {
      try
      {
        cout << "Here is the constant array v: \n";

        cout << setw(8) << v <<endl;

        int i;
        cout << "Index? "; cin >> i;
        cout << "\nThe value read: " <<  v[i] << endl;
        ok = true;
      }
      catch(BadIndex& err)
      {
        cerr << "Error in reading.\n"
             << "\nInvalid index: " 
             << err.getBadIndex() << endl;
      }
    }
 
    FloatArr w(20);             // Array w 
    try
    {
        w.insert(1.1F, 0);      // To write.
        w.insert(2.2F, 1);

//      w.insert(3.3F, 3);      // Error! Length == 2
//      w[10] = 5.0;            // Error! 
//      w.remove(7);            // Error!

        w.insert(0.0F, 0);      // ok!
        w.insert(3.3F, 3);      // now ok!
        w.remove(0);

    }
    catch(BadIndex& err)
    {
        cerr << "\nError in writing! "
             << "\nInvalid index: " 
             << err.getBadIndex() << endl;
    }

    cout << "\nHere is the array w: \n";
    cout << setw(5) << w << endl;

    return 0;
}
