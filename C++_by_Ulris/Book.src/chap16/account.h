// account.h 
// Defines class Account.
// ---------------------------------------------------

#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Account
{
   private:                   // Sheltered members:
      string name;                 // Account holder
      unsigned long nr;            // Account number
      double balance;              // Account balance

   public:                    // Public interface:
     Account( const string& a_name = "X",
              unsigned long a_nr   = 1111111L,
              double  a_balance    = 0.0)
     :name(a_name), nr(a_nr), balance(a_balance)    
     { }

     // get methods:
     const string& getName()    const { return name; }
     unsigned long getNr()      const { return nr; }
     double        getBalance() const { return balance; }

     // set methods:
     bool setName( const string& s)
     {
        if( s.size() < 1)     // No empty name
          return false;
        name = s;
        return true; 
     }
     void setNr( unsigned long n) { nr = n; }
     void setBalance(double x) { balance = x; }

       
     void display() const
     {
         cout << fixed << setprecision(2)
              << "--------------------------------------\n"
              << "Account holder:  "   << name    << '\n'
              << "Account number:  "   << nr      << '\n'
              << "Account balance:   " << balance << '\n'
              << "--------------------------------------" << endl;
     }

};
 
#endif   //  _ACCOUNT_
