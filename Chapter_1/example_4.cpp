#include <iostream>
#include <string>
using namespace std;

int main()
{
    int farenheitValue, centigrateValue;
    int count;

    cout << "Enter Temp value in F to convert to C: ";
    cin >> farenheitValue;

    cout << "Celsius\t\t"
         << "Fahrenheit\n";
    centigrateValue = (farenheitValue - 32) * 0.5556;
    cout << farenheitValue << '\t' << '\t' << centigrateValue << '\n';

    return 0;
}