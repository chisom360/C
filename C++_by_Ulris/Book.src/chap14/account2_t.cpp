// account2_t.cpp 
// Using the constructors of class Account.
// ---------------------------------------------------

#include "account.h"

int main()
{
   Account giro("Cheers, Mary", 1234567, -1200.99 ),
           save("Lucky, Luke");

//   Account depot;   // Error: no default constructor defined.

   giro.display();         // To output
   save.display();

   Account temp("Funny, Susy", 7777777, 1000000.0);
   save = temp;            // ok: Assignment of 
                           //     objects possible.
   save.display();

   // Or by the presently available method init():
   save.init("Lucky, Luke", 7654321, 1000000.0);
   save.display();

   return 0;
}
