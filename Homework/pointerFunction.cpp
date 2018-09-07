#include <iostream>
using namespace std;

int addNumber(int a, int b)
{
    return a + b;
}

int subNumber(int c, int d)
{
    return c - d;
}
int main()
{
    int (*pFunction)(int, int) = addNumber;
    cout << pFunction(9, 1) << "\n\n";

    pFunction = subNumber;
    cout << pFunction(10, 7) << endl;

    return 0;
}

typedef int add