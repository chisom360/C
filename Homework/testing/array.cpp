#include <iostream>

using namespace std;

int sum(int[], int);
int main()
{
    int a[] = {11, 33, 55, 77};
    int size = sizeof(a) / sizeof(int);
    cout << "sum(a,size) = " << sum(a, size) << endl;
}
int sum(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}