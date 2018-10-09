// -------------------------------------------------------
// minivar.cpp
// Defines and tests the function min(), which 
// computes and returns the minimum of positive integers. 
// The function expects a variable number of arguments
// with unsigned int types.
// The last argument must be 0!
// -------------------------------------------------------
#include <stdarg.h>

unsigned int min( unsigned int first, ... )
{
    unsigned int minarg, arg;

    va_list argptr;  // Pointer to optional arguments

    if( first == 0)
        return 0;

    va_start( argptr, first);

    minarg = first;
    while( (arg = va_arg(argptr, unsigned int) ) != 0)
        if( arg < minarg)
            minarg = arg;

    va_end (argptr);

    return minarg;
}

// ----- A small function main() for testing---------------
#include <iostream>
using namespace std;

int main()
{
    cout << "\nThe minimum of : 34 47 19 22 58 " 
         << "is:  " << min(34, 47, 19, 22,58, 0)
         << endl;

    return 0;
}
