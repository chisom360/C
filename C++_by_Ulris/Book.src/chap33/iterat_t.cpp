// ---------------------------------------------------
// iterat_t.cpp: To output an array of accounts.
// ---------------------------------------------------
#include <vector>
#include <iostream>
using namespace std;

#include "account.h"

typedef vector<Account> AccVec;                          // Account vector

void display(const AccVec& v);

int main()
{
    AccVec kv;

    kv.push_back( Account("George", 12345UL, 1950.99));  // To insert
    kv.push_back( Account("Bill",   54321UL, 1150.99));
    kv.push_back( Account("Ronald", 98765UL,  950.99));

    display(kv);                                         // To output

    return 0;
}

void display(const AccVec& v)
{
   AccVec::const_iterator pos;        // Iterator

   for( pos = v.begin(); pos < v.end(); pos++)
       pos->display();
   cout << endl;
}
