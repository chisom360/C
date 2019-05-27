#include <iostream>
using namespace std;

/*
int sum(int (*)(int), int);
int square(int);
int cunbe(int);
*/

int sum(int (*pf)(int k), int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += (*pf)(i);

    return s;
}

int square(int k)
{
    return k * k;
}

int cube(int k)
{
    return k * k * k;
}
int main()
{
    cout << sum(square, 4) << endl;
    cout << sum(cube, 4) << endl;
}
