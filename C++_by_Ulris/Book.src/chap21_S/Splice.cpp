// ----------------------------------------------------
// Splice.cpp 
// Implements the splice algorithm.
// ----------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>         // For srand() and rand()
#include <ctime>           // and for time().
using namespace std;

// Prototype:
int *splice( int v1[], int len1,
             int v2[], int len2, int pos);

int main()
{
    cout << "\n  * * * Testing the splice function * * *\n"
         << endl;

    int i, len1 = 10, len2 = 5;
    int *a1 = new int[len1],
        *a2 = new int[len2];

    // Initialize the random number generator 
    // with the current time:
    srand( (unsigned)time(NULL));  

    for( i=0; i < len1; ++i)    // Initialize the arrays: 
       a1[i] = rand();          // with positive and
    for( i=0; i < len2; ++i) 
       a2[i] = -rand();         // negative numbers.

    // To output the array:
    cout << "1. array: " << endl;
    for( i = 0; i < len1; ++i)
       cout << setw(10) << a1[i];
    cout << endl;

    cout << "2. array: " << endl; 
    for( i = 0; i < len2; ++i)
       cout << setw(10) << a2[i];
    cout << endl;

    cout << "\n At what position do you want to insert "
            "\n the 2nd array  into 1st  array?"
            "\n Possible positions: 0, 1, ..., " << len1
         << " : ";

    int pos;  cin >> pos;

    int *a3, len3 = len1 + len2;
    a3  = splice( a1, len1, a2, len2, pos);

    if( a3 == NULL)
       cerr << "\n Invalid position!\n" << endl;
    else
    {
       cout << " The new spliced array: " << endl;
       for( i = 0; i < len3; ++i)
          cout << setw(10) << a3[i];
       cout << endl;
    }

    delete[] a1;   delete[] a2;   delete[] a3;

    return 0;
}

// -------------------------------------------------------
//  Function splice() inserts the array v2 into v1
//  starting at position pos.

int *splice( int v1[], int len1,
             int v2[], int len2, int pos)
{
    if( pos < 0  ||  pos > len1)
       return NULL;

    int i = 0, i1 = 0, i2 = 0;
    int *v = new int[len1+len2];

    for( i = 0, i1 = 0; i1 < pos;  ++i, ++i1) // 1st part
        v[i] = v1[i1];

    for( i2 = 0; i2 < len2;  ++i, ++i2)       // 2nd part
        v[i] = v2[i2];

    for(  ; i1 < len1;  ++i, ++i1)            // 3rd part
        v[i] = v1[i1];

    return v;
}
