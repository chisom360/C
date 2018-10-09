// pointer1.cpp
// Prints the values and addresses of variables.
// --------------------------------------------------
#include <iostream>
using namespace std;

int var, *ptr;    // Definition of variables var and ptr

int main()        // Outputs the values and addresses 
{                 // of the variables var and ptr.
   var = 100;
   ptr = &var;
   
   cout << " Value of var:      " <<  var
        << "   Address of var: " <<  &var
        << endl;

   cout << " Value of ptr: "      <<  ptr
        << "   Address of ptr: " <<  &ptr
        << endl;
   return 0;
}
