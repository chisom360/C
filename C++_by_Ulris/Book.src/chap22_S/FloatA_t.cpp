// -----------------------------------------------------
// FloatA_t.cpp
// Tests the class FloatArr.
// -----------------------------------------------------

#include "FloatArr.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    FloatArr v(10);        // Array v for 10 float values

    FloatArr w(15, 1.0F);  // Initialize the array w of
                           // 15 float values with 1.0.

    cout << "Current total of elements in v: " 
         << v.length() << endl;
    cout << "Current total of elements in w: " 
         << w.length() << endl;

    float x = -5.0F;             // Append values.
    for( ; x < 6 ; x += 1.7F)
       v.append(x);

    v += v;                      // Also possible!

    cout << "\nThe array elements after appending:"
         << endl;
    cout << setw(5) << v << endl;

    const FloatArr cv(v);        // Copy constructor 
                                 // creates const object.
    cout << "\nThe copy of v has been created.\n";
    cout << "\nThe array elements of the copy:\n"
         << setw(5) << v << endl;

    w.remove(3);           // Erase the element at 
                           // position 3.
    w.append(10.0F);       // Add a new element.
    w.append(20.0F);       // And once more!

    v = w;
    cout << "\nAssignment done.\n";
    cout << "\nThe elements after assigning: \n"
         << setw(5) << v << endl;

    v.insert( cv, 0);
    cout << "\nThe elements after inserting "
            " the copy at position 0: \n"
         << setw(5) << v << endl;

    return 0;
}
