// StrToL_t.cpp
// Testing the function strToLong() 
// ------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

long strToLong( string);

int main()
{
    string numStr = " \t -123 USD";
    long n = strToLong( numStr); 
    cout << "Result of the conversion: " << n << endl;

    cout << "Enter a test string including an integer:"
         << endl;
    getline( cin, numStr);
    cout << "Your input: " << numStr << endl;

    n = strToLong( numStr); 
    cout << "The double of number " << n << " is " << 2*n << endl;

    return 0;
}
