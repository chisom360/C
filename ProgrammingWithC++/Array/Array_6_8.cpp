#include <iostream>
#include <cassert>

using namespace std;

float min(float a[], int n)
{
    assert(n >= 0);
    float min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        return min;
    }
}

int main()
{
    int n = 5;
    float a[n] = {2, 4, 6, 8, 9};
    cout << " Min array value :" << min(a, n) << endl;
}