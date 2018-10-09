// -------------------------------------------------------
// account_t.cpp 
// Tests the classes DepAcc and SavAcc 
// derived from class Account
// -------------------------------------------------------
#include "account.h"

int main()
{
   string s;
   double rt;

   SavAcc mickey("Mickey Mouse", 1234567, 200.40, 3.5);
   mickey.display();

   cout << "New name:          "; getline(cin, s);
   cout << "New interest rate: "; cin >> rt;

   mickey.setName(s);
   mickey.setInterest(rt);
   mickey.display();

   DepAcc donald("Donald Duck", 7654321,
                 -1245.56, 10000, 12.9);
   donald.display();

   cout << "New limit:  ";   cin >> rt;
   donald.setLimit(rt);
   donald.display();

   return 0;
}
