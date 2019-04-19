#include <iostream>
#include <cassert>

using namespace std;

void getExtremes(float &min, float &max, float a[], int n)
{
    assert(n >= 0);
    min = max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
        else if (a[i] > max)
            max = a[i];
}

int main()
{
    int n = 7;
    float a[n] = {2, 6, 1, 12, 455, 2, 3000};
    float max1;
    float max2;
    getExtremes(max1, max2, a, n);
    cout << "Min:" << max1 << endl;
    cout << "Max :" << max2 << endl;

    cout << endl;
}