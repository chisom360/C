#include <iostream>
using namespace std;

int index(int, int[], int);
int main()
{
    int a[] = {22, 44, 66, 88, 44, 66, 55};
    cout << "index(44,a,7) = " << index(44, a, 7) << endl;
    cout << "index(50,a,7) = " << index(50, a, 7) << endl;
}

int index(int x, int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n; // x not found
}
