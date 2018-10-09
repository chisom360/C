// -----------------------------------------------------
// account.h: 
// Defines the classes Account, DepAcc and SavAcc.
// ----------------------------------------------------- 
#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <iostream>
#include <iomanip>
#include <string> 
using namespace std;

class Account
{
  private:
    string name;   unsigned long nr;    double balance;

  public:
    Account(const string& s="X", unsigned long n = 1111111L,
            double bl = 0.0)
    : name(s), nr(n), balance(bl)
    { } 
    const string& getName() const  { return name; }
    void  setName(const string& n) { name = n;}

    unsigned long getNr() const { return nr; }
    void setNr(unsigned long n) { nr = n; }

    double getBalance() const   { return balance; }
    void   setBalance(double bl){ balance = bl; }

    void display()
    {
       cout << fixed << setprecision(2)
            << "----------------------------------------\n"
            << "Account holder:         " << name  << endl
            << "Account number:         " << nr    << endl
            << "Balance of the account: " << balance <<endl;
    }
};

class DepAcc : public Account
{
  private:
    double limit;                // Overdraft limit
    double interest;             // Interest rate

  public:
    DepAcc(const string& s = "X",
           unsigned long n = 1111111L, double bl = 0.0,
           double li = 0.0, double in = 0.0)
    : Account(s, n, bl), limit(li), interest(in)
    { }
 
                               // Access methods:
    double getLimit() const    { return limit; }
    void   setLimit(double lt) { limit = lt; }
    double getInterest() const { return interest; }
    void   setInterest(double in){ interest = in; }

    void display()
    {   
       Account::display();
       cout << fixed << setprecision(2)
            << "Overdraft limit:        " << limit << endl
            << "Interest rate:          " << interest << endl
            << "----------------------------------------\n"
            << endl;
    }
};
 
class SavAcc: public Account
{
  private:
    double interest;               // compound interest

  public:
    SavAcc(const string& s = "X",
           unsigned long n = 1111111L, double bl = 0.0,
           double in = 0.0)
    : Account(s, n, bl), interest(in)
    { } 

    // Access methods.
    double getInterest() const    { return interest; }
    void   setInterest(double in) { interest = in; }

    void display()
    {   
       Account::display();
       cout << fixed << setprecision(2)
            << "Interest rate:          " << interest << endl
            << "----------------------------------------\n"
            << endl;
    }
};

#endif

