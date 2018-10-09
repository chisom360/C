// coworker.cpp: Methods of the classes Coworker,
//               Laborer and Employee.
// -------------------------------------------------

#include "coworker.h"

Coworker& Coworker::operator=(const Coworker & m)
{
   if( this != &m )         // No self assignment
    name = m.name;
 
   return *this;
}

void Coworker::display() const
{
    cout << "\n--------------------------------"
         << "\nName:           " << name;
}

/*
// Redefinition: virtual  
// Redefining a virtual function which returns a reference to
// the derived class is not yet supported by all compilers.
Employee& Employee::operator=(const Coworker& m)
{
   if( this != &m )         // No self assignment
   {
     Coworker::operator=( m );
     salary = 0.0;
   }
 
   return *this;
}
*/

// Redefinition: virtual  
Coworker& Employee::operator=(const Coworker& m)
{
   if( this != &m )         // No self assignment
   {
     Coworker::operator=( m );
     salary = 0.0;
   }
 
   return *this;
}
 
// Standard Assignment: not virtual  
Employee& Employee::operator=(const Employee& a)
{
   if( this != &a )
   {
      Coworker::operator=( a );
      salary = a.salary;
   }
   return *this;
}

void Employee::display() const
{
   Coworker::display();
   cout << "\nSalary:         " 
        << fixed << setprecision(2) << salary << endl;
}

/*
// Redefinition: virtual  
// Redefining a virtual function which returns a reference to
// the derived class is not yet supported by all compilers.
Laborer& Laborer::operator=(const Coworker& m)
{
   if( this != &m )         // No self assignment
   {
     Coworker::operator=( m );
     wages = 0.0;
     hr  = 0;
   }
 
   return *this;
}

*/

// Redefinition: virtual  
Coworker& Laborer::operator=(const Coworker& m)
{
   if( this != &m )         // No self assignment
   {
     Coworker::operator=( m );
     wages = 0.0;
     hr  = 0;
   }
 
   return *this;
}

// Standard assignment: not virtual  
Laborer& Laborer::operator=(const Laborer& a)
{
  if( this != &a )
  {
      Coworker::operator=( a );
      wages = a.wages;
      hr  = a.hr;
  }
  return *this;
}

void Laborer::display() const
{  
   Coworker::display();
   cout << fixed << setprecision(2) 
        << "\nWages per hour:    " << wages
        << "\nNumber of hours:   " << hr << endl;
}
