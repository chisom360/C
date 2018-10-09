// account.h 
// Class Account with methods read() and write().
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
              double  a_balance      = 0.0)
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
       
     istream& read( istream& is);
     ostream& write( ostream& os) const;

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

// write() outputs an account into the given stream os.
// Returns: The given stream.
inline ostream& Account::write(ostream& os) const
{
   os << name << '\0';         // To write a string 
   os.write((char*)&nr, sizeof(nr) );
   os.write((char*)&balance, sizeof(balance) );
   return os;
}

// read() is the opposite function of write().
// read() inputs an account from the stream is
// and writes it into the members of the current object

inline istream& Account::read(istream& is)
{
   getline( is, name, '\0');   // Read a string
   is.read( (char*)&nr, sizeof(nr) );
   is.read( (char*)&balance, sizeof(balance)); 
   return is;
}

#endif   //  _ACCOUNT_
