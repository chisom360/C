// accountFct.cpp
// Defines and calls a function, which outputs
// a list of overdrawn accounts.
// -------------------------------------------------- 

#include "account.h"     // Definition of class Account.

Account accountTab[] =   // Table with Account-objects.
{  Account("Twain, Mark", 1234567, -3434.30),
   Account("Crusoe, Robinson", 200000, 0.00), 
   Account("Temple, Shirley", 543001, +777.70),
   Account("Valentin, Carl", 543002, -1111.10),
};

int cnt = sizeof(accountTab) / sizeof(Account);

// Prototype:
int displayOverdraw( const Account *aTab, int cnt,
                     double limit);
int main()
{
   double limit = 0.0;

   cout << "Outputs the overdrawn accounts!\n" 
        << "These are the accounts, which fell below \n"
        << "the limit, e.g. -1000.00.\n" << endl;

   cout << "What is the limit? ";
   cin >> limit;

   cout << "Listing the overdrawn accounts:\n" << endl;

   if( displayOverdraw( accountTab, cnt, limit) == 0)
     cout << "\nNo account found!"
          << endl;

   return 0;
}

int displayOverdraw( const Account *aTab, int cnt,
                     double limit)
{ 
   int count = 0;
   
   const Account* aPtr;
   
   for( aPtr = aTab;  aPtr < aTab + cnt;  ++aPtr)
      if( aPtr->getBalance() < limit )  // Below the limit?
      {
         aPtr->display();               // Yes -> display. 
         ++count;
      }
   
    return count;
}
