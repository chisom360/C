// AccountTab.cpp 
// An array containing objects of class Account.
// ---------------------------------------------------

#include "account.h"      // Definition of class Account
#include <iostream>
using namespace std;

Account giro("Lucky, Peter", 1234567, -1200.99 );
Account accountTab[] =
{
  Account("Tang, Sarah", 123000, 2500.0),
  Account("Smith, John", 543001),
  Account(),                    // Default constructor
  "Li, Zhang",                  // Account("Li, Zhang"),
  giro                          // Account(giro)
};

int cnt = sizeof(accountTab) / sizeof(Account);

int main()
{
   // To set some values:
   accountTab[1].setBalance( 10000.00);
                                     // Assignment ok:
   accountTab[2] = Account("Sad, Otto", 727003, 200.00);

   cout << "The accounts in the table:" << endl;
   for( int i = 0; i < cnt; ++i)
   {
      accountTab[i].display();
      if( i % 3 == 2)
      {
         cout << "Press return to go on!\n";
         cin.get();
      }
   }
   cout << endl;

   return 0;
}
