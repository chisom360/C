#include <iostream>
#include <cassert>

using namespace std;

void largest(float &max1, float &max2, float a[], int n)
{
    assert(n >= 1);
    int i1 = 0, i2;
    for (int i = 1; i < n; i++)
        if (a[i] > a[i1])
            i1 = i;
    max1 = a[i1];
    i2 = (i1 == 0 ? 1 : 0);
    for (int i = i2 + 1; i < n; i++)
        if (i != i1 && a[i] > a[i2])
            i2 = i;
    max2 = a[i2];
}

int main()
{
    int n = 7;
    float a[n] = {2, 6, 1, 12, 455, 2, 3000};
    float max1;
    float max2;
    largest(max1, max2, a, n);
    //getExtremes(max1, max2, a, n);
    cout << "Min:" << max1 << endl;
    cout << "Max :" << max2 << endl;

    cout << endl;
}