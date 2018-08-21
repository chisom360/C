/*
// template arguments
#include <iostream>
using namespace std;

template <class T, int N>
T fixed_multiply (T val)
{
  return val * N;
}

int main() {
  std::cout << fixed_multiply<int,2>(10) << '\n';
  std::cout << fixed_multiply<int,3>(10) << '\n';
}
*/

// function template
#include <iostream>
using namespace std;

/*
template <class T>
T sum(T a, T b)
{
    T result;
    result = a + b;
    return result;
}

int main()
{
    int i = 5, j = 6, k;
    double f = 2.0, g = 0.5, h;
    k = sum<int>(i, j);
    h = sum<double>(f, g);
    cout << k << '\n';
    cout << h << '\n';
    
*/

template <class T, class U>
bool are_equal(T a, U b)
{
    return (a == b);
}

int main()
{
    if (are_equal<int, double>(11, 10.0))
        cout << "x and y are equal\n";
    else
        cout << "x and y are not equal\n";
    return 0;
}