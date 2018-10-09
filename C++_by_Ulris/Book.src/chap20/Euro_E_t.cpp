// Euro_E_t.cpp 
// Tests explicit conversion of class Euro.
// ---------------------------------------------------

#include "Euro_Ex.h"        // Class definition
#include <iostream>
using namespace std;
int main()
{
    Euro salary( 8888.8);      // double constructor 
    double x(0.0);

    /* Now impossible:
    salary += 1000;            // implicit int -> Euro
    salary += 0.10;            // implicit double -> Euro
    salary = 7777.77; 
    x = salary;                // implicit Euro -> double
    x = (double)salary;        // There is no method 
                               // operator double().
    */
    // The following conversions are ok:
    salary = Euro( 7777.77);   // explicit double -> Euro
    salary += Euro(1000.10);  
    x = salary.asDouble();     // explicit by method
                               // Euro -> double.
    int i = salary.asDouble(); // Euro -> double -> int
                                               // Output:
    cout << " salary = " << salary << endl;    // 8777,87 Euro
    cout << "      x = " << x << endl;         // 8777.87
    cout << "      i = " << i << endl;         // 8777

    return 0;
}
