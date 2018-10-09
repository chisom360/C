// account.h 
// Defining the class Account.
// ---------------------------------------------------
#ifndef _ACCOUNT_       // Avoid multiple inclusions.
#define _ACCOUNT_

#include <iostream>
#include <string>
using namespace std;

class Account
{
   private:                   // Sheltered elements:
     string name;                // Account holder
     unsigned long nr;           // Account number
     double balance;             // Account balance

   public:                    //Public interface:
     bool init( const string&, unsigned long, double);
     void display();
};

#endif   //  _ACCOUNT_
