

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    /* http://www.cppforschool.com/assignment/variable_1.html
    Problem Set 1, number 2*/

    cout << "Subject" << setw(19) << "Marks" << '\n'
         << "Mathematics  " << setw(10) << "90" << '\n'
         << "Computer   " << setw(12) << "77" << '\n'
         << "Chemistry   " << setw(11) << "69" << '\n';

    cout << "subject "
         << "\tmarks"
         << "\nmathematic\t"
         << 90 << "\ncomputer\t" << 77 << "\nchemistry\t" << 69 << '\n';

    return 0;
}
