// range-based for loop
#include <iostream>
using namespace std;

int main()
{
    /*
    int n;

    cout << "Enter a number: ";
    cin >> n;
    (n % 2 == 0) ? cout << n << " is an Even Number" : cout << n << " is an Odd number" << endl;
    return 0;
    */

    int absNumber;

    cout << "Number to find absolute value of : ";
    cin >> absNumber;

    if (absNumber < 0)
        cout << "Absolute number of " << absNumber << " is " << absNumber * -1 << endl;
    else
        cout << "Absolute number of " << absNumber << " is " << absNumber << endl;

    return 0;
}
