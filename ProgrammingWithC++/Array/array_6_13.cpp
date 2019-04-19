#include <iostream>
using namespace std;

void remove(float a[], int &n, int i)
{
    for (int j = i + 1; j < n; j++)
        a[j - 1] = a[j];
    --n;
}
void print(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}
int main()
{
    int i = 4;
    int n = 10;
    float a[n] = {1, 2, 3, 5, 4, 6, 7, 8, 9, 4};
    print(a, n);
    remove(a, n, i);
    cout << endl;
    print(a, n);
}