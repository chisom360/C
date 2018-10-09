// coworker.h:  Defining the abstract class Coworker and
//              the derived classes Laborer and Employee.
// ----------------------------------------------------
#ifndef _COWORKER_H
#define _COWORKER_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Coworker
{
   private:
     string name;
     // more informations 
   
   public:
     Coworker( const string& s = "") { name = s; }
     virtual ~Coworker() {}                // Destructor

     const string&  getName() const { return name; }
     void  setName( const string& n){ name = n; }

     virtual void display() const;

     virtual double income() const = 0;

     virtual Coworker& operator=(const Coworker&);
};


class Laborer : public Coworker
{
   private:
     double wages;             // Pay per hour
     int    hr;

   public:
     Laborer(const string& s="", double w=0.0, int h=0)
     : Coworker(s), wages(w), hr(h){ }

     double getWages() const { return wages; }
     void   setWages( double w ){ wages = w; }

     int    getHr() const { return hr; }
     void   setHr(int h ) { hr = h; }

     void   display() const;
     double income() const{ return wages * hr; }
 
//   Laborer&  operator=(const Coworker&); 
     Coworker& operator=(const Coworker&); 
     Laborer& operator=(const Laborer&);  
};


class Employee : public Coworker
{
   private:
     double salary;       // Pay per month
  
   public:
     Employee( const string& s="", double sa = 0.0)
     : Coworker(s), salary(sa){ }

     double getSalary() const { return salary; }
     void   setSalary( double sa){ salary = sa; }

     void   display() const;
     double income() const { return salary; }

//   Employee& operator=( const Coworker& );
     Coworker& operator=( const Coworker& );
     Employee& operator=( const Employee& );   
};

#endif  // _Coworker_H
