#include <iostream>
using namespace std;

int *location(int a[], int n, int target)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == target)
            return &a[i];
    }
    return NULL;
}

int main()
{
    int a[8] = {22, 33, 44, 55, 66, 77, 88, 99};
    int *p = 0;
    int c;
    do
    {
        cin >> c;
        if (p = location(a, 8, c))
            cout << p << "," << *p << endl;
        else
            cout << c << " was not found. \n";
    } while (c > 0);
}