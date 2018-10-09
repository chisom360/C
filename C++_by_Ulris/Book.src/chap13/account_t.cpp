// account_t.cpp 
// Uses objects of class Account.
// ---------------------------------------------------

#include "account.h"

int main()
{
   Account current1, current2;

   current1.init("Cheers, Mary", 1234567, -1200.99);
   current1.display();

//   current1.balance += 100;   // Error: private member

   current2 = current1;         // ok: Assignment of 
                                // objects is possible.
   current2.display();          // ok
 
                                // New values for current2
   current2.init("Jones, Tom", 3512347, 199.40);
	
   current2.display(); 
                                // To use a reference:
   Account& CM = current1;      // CM is an alias name
                                // for object current1. 
   CM.display();               // CM can be used just 
                                // as object current1.
   return 0;
}
