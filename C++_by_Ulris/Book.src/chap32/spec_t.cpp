// spez_t.cpp: Zum Testen von Spezialisierungen
// -----------------------------------------------
#include <cstring>
#include <iostream>
using namespace std;

// Funktions-Template:
template <class T>  T min( T x, T y);

// ANSI-Spezialisierung:
template<>
const char* min( const char* s1, const char* s2 );

int main()
{
    int x = 1, y = 10;

    cout << "\n1. Zahl: " << x << "\n2. Zahl: " << y << endl
         << "\nDie kleinere Zahl: " << min(x,y)  << endl;

    cout << "\n1. String: GROSS  \n2. String: gross" << endl;
    cout << "\nDer kleinere String: " 
         << min("GROSS", "gross") << endl;

    return 0;
}



template <class T>
T min( T x, T y)
{
    return( (x < y) ? x : y);
}
 

