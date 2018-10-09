// account.h 
// Defining class Account with two constructors.
// ---------------------------------------------------

#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <string>
using namespace std;

class Account
{
   private:                   // Sheltered members:
     string name;                // Account holder
     unsigned long nr;           // Account number
     double balance;             // Account balance

   public:                    // Public interface:
     Account( const string&, unsigned long, double );
     Account( const string& );
     bool init( const string&, unsigned long, double);
     void display();
};

#endif   //  _ACCOUNT_
