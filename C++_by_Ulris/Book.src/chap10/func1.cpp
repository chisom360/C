// func1.cpp

#include <iostream>
using namespace std;
 
void test( int, double );               // Prototype

int main()
{
   cout << "\nNow function test() will be called.\n";

   test( 10, -7.5);                     // Call

   cout << "\nAnd back again in main()." << endl;

   return 0;
}

void test( int arg1, double arg2)       // Definition
{
   cout << "\nIn function test()."
        << "\n  1. argument: " << arg1
        << "\n  2. argument: " << arg2 << endl;
}
