#include <iostream>
using namespace std;

double *copy(double a[], int n)
{
    double *p = new double[n];
    for (int i = 0; i < n; i++)
        p[i] = a[i];

    return p;
}

void print(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << a[i];
    }
    cout << endl;
}

int main()
{
    const int SIZE = 8;
    double a[SIZE] = {22.2, 33.3, 44.4, 55.5, 66.6, 77.7, 88.8, 99.9};
    print(a, SIZE);
    double *b = copy(a, SIZE);
    a[2] = a[4] = 11.1;
    print(a, SIZE);
    print(b, SIZE);
}