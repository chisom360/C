// min_spec.cpp: Tests Spezializations
// -----------------------------------------------

#include <cstring>
#include <iostream>
using namespace std;

// Function template:
//template <class T>  T min( T x, T y);
template <class T>
T min( T x, T y)
{
    return( (x < y) ? x : y);
}

// ANSI specialization:
template<>
const char* min( const char* s1, const char* s2 )
{
   return( (strcmp(s1, s2) < 0 ) ? s1: s2 );
}

int main()
{
    int x = 1, y = 10;

    cout << "\n1st number: " << x 
         << "\n2nd number: " << y << endl;
    cout << "The smaller number: " << min(x,y)  << endl;

    
    const char str1[] = "CAPITAL",  str2[] = "capital";
    cout << "\n1st string: " << str1
         << "\n2nd string: " << str2 << endl;
    cout << "The smaller string: " 
         << min( str1, str2) << endl;

    return 0;
}
