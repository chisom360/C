#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int start;
    int end;

    cout << "Enter the starting point for your ACII convertion: ";
    cin >> start;
    cout << "Enter were you want the conversion to end: ";
    cin >> end;
    cout << "\n\n";
    cout << "DEC" << setw(10) << "Hex" << setw(10) << "OCT"
         << setw(10) << "Char" << '\n';
    cout << "=================================" << endl;
    for (start; start <= end; start++)
    {
        cout << start << setw(10)
             << hex << setw(10) << start
             << setw(10) << oct << setw(10) << start
             << setw(10) << char(start) << endl;
    }
    return 0;
}
#include <iostream>
