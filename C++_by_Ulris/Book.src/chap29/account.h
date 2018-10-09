// ------------------------------------------------------ 
// account.h : 
// Defines the classes 
//       Account, DepAcc and SavAcc
// with virtual read and write methods as well as
// the class AccFile to represent account files.
// ------------------------------------------------------
#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string> 
using namespace std;

#include "exceptio.h"

enum TypeId { ACCOUNT, DEP_ACC, SAV_ACC };

class Account
{
  private:                      // Data members:
    string name;
    unsigned long nr;
    double balance;

  public:                        // Constructor:
    Account( const string c_name  = "X",
             unsigned long c_nr   = 1111111L,
             double c_balance     = 0.0)
    : name(c_name), nr(c_nr), balance(c_balance)
    { } 

    virtual ~Account() {}        // Virtual destuctor

     // Access methods here:
    const string& getName() const  { return name; }
    bool  setName(const string& n)
    {
       if( n.size() < 1)     // No empty name
         return false;
       name = n;
       return true; 
    }
    long getNr() const { return nr; }
    void setNr(unsigned long n){ nr = n; }

    double getBalance() const   { return balance; }
    void   setBalance(double bl){ balance = bl; }

    // The other methods:
    virtual TypeId getTypeId() const { return ACCOUNT; }

    virtual ostream& write(ostream& fs) const;
    virtual istream& read(istream& fs); 
       
    virtual void display() const
    { 
       cout << fixed << setprecision(2)
            << "----------------------------------\n"
            << "Account holder:       " << name    << endl
            << "Account number:       " << nr      << endl
            << "Balance of account:   " << balance << endl
            << "----------------------------------"
            << endl;
    }
};

class DepAcc : public Account
{
  private:
    double limit;           // Overdrawn limit
    double interest;        // Interest rate

  public:
    DepAcc(const string s = "X", unsigned long n = 1111111L,  double bal = 0.0,
           double li = 0.0, double ir = 0.0)
    : Account(s, n, bal), limit(li), interest(ir)
    { } 

    // Access methods:
    double getLimit() const    { return limit; }
    void   setLimit(double lt) { limit = lt; }
    double getInterest() const { return interest; }
    void   setInterest(double ir) { interest = ir;}

    // The other methods are implicit virtual:
    TypeId getTypeId() const { return DEP_ACC; }

    ostream& write(ostream& fs) const;
    istream& read(istream& fs); 

    void display() const
    {   
        Account::display();
        cout << "Overdrawn limit:      " << limit << endl
             << "Competitive interest: " << interest
             << "\n----------------------------------\n"
             << endl;
    }
};
  
class SavAcc: public Account
{     
  private:
    double interest;            // Compound interest

  public:
   // Methods as in class DepAcc.
    SavAcc(const string s = "X", unsigned long n = 1111111L,  double bal = 0.0,
           double ir = 0.0)
    : Account(s, n, bal), interest(ir)
    { } 

    // Access methods:
    double getInterest() const    { return interest; }
    void   setInterest(double in) { interest = in; }

    TypeId getTypeId() const { return SAV_ACC; }

    ostream& write(ostream& fs) const;
    istream& read(istream& fs); 
      
    void display() const
    {   
        Account::display();
        cout << fixed << setprecision(2)
             << "Compound interest:    " << interest << endl
             << "----------------------------------\n"
             << endl << endl;
    }
};

// Definition of class AccFile
// --------------------------------------------------
class AccFile
{
  private:
    fstream f;             // Stream
    string  name;          // Filename

  public:
    AccFile(const string& s) throw(OpenError);
    ~AccFile(){ f.close(); }

    long append( Account& acc)   throw(WriteError);
    Account* retrieve( long pos) throw(ReadError);

    void display() throw( ReadError);
};

#endif
