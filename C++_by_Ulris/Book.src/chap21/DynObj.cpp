// DynObj.cpp 
// The operators new and delete for classes.
// ---------------------------------------------------

#include "account.h"
#include <iostream>
using namespace std;

Account *clone( const Account* pK);  // Create a copy 
                                     // dynamically.
int main()
{
   cout << "Dynamcally created objects.\n" << endl;

   // To allocate storage:
   Account *ptrA1, *ptrA2, *ptrA3;
 
   ptrA1 = new Account;      // With default constructor
   ptrA1->display();         // Show default values.

   ptrA1->setNr(302010);         // Set the other
   ptrA1->setName("Tang, Ming"); // values by access
   ptrA1->setBalance(2345.87);   // methods.
   ptrA1->display();             // Show new values. 
 
   // Use the constructor with three arguments:
   ptrA2 = new Account("Xiang, Zhang", 7531357, 999.99);
   ptrA2->display();            // Display new account.
 
   ptrA3 = clone( ptrA1);       // Pointer to a dyna-
                                // mically created copy.
   cout << "Copy of the first account: " << endl;
   ptrA3->display();            // Display the copy.
 
   delete ptrA1;                // Release memory
   delete ptrA2;
   delete ptrA3;

  return 0;
}

Account *clone( const Account* pK)   // Create a copy
{                                    // dynamically.
    return new Account(*pK);
}
