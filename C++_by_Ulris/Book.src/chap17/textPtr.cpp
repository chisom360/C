// textPtr.cpp 
// Using arrays of char and pointers to char
// -----------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
   cout << "Demonstrating arrays of char "
        << "and pointers to char.\n"
        << endl;

   char text[] = "Good morning!",
        name[] = "Bill!";

   char *cPtr = "Hello ";          // Let cPtr point
                                   // to "Hello ".
   cout << cPtr << name << '\n'
        << text << endl;

   cout << "The text \"" << text
        << "\" starts at address " << (void*)text
        << endl;

   cout << text + 5      // What happens now?
        << endl;

   cPtr = name;    // Let cPtr point to name, i.e. *cPtr
                   // is equivalent to name[0] 
   cout << "This is the " << *cPtr << " of " << cPtr
        << endl;

   *cPtr = 'k';
   
   cout << "Bill can not " << cPtr << "!\n" << endl;
   
   return 0;
}

/*
Sample output:

 Demonstrating arrays of char and pointers to char.

 Hello Bill!
 Good Morning!
 The text "Good morning!" starts at address 00451E40
 morning!
 This is the B of Bill!
 Bill can not kill!
*/
