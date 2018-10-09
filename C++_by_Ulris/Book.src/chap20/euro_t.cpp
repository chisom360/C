// -----------------------------------------------------
// Euro_t.cpp : Testing conversions of class Euro.
// -----------------------------------------------------

#include "Euro.h"           // Definition of the class
#include <iostream>
using namespace std;
int main()
{
    cout << " * * *  Testing Conversions  * * * \n" << endl;

    Euro salary( 8888,80);
    double x(0.0);

    salary += 1000;         // implicit int -> Euro
    salary += 0.10;         // implicit double -> Euro
    x = salary;             // implicit Euro -> double
    x = (double)salary;     // explicit Euro -> double
    x = salary.operator double();    // also possible!

    // Constructor style is also safe for built-in types:
    x = double(salary); 

    int i = salary;         // Euro -> double -> int
                                               // Output:
    cout << " salary = " << salary << endl;    // 9888,90 Euro
    cout << "      x = " << x << endl;         // 9888.9
    cout << "      i = " << i << endl;         // 9888

    return 0;
}
