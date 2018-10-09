// ------------------------------------------------------
// car.cpp
// Implementing the methods of Car and PassCar
// ------------------------------------------------------

#include "car.h"

// ------------------------------------------------------
// The methods of baseclass Car:

Car::Car( long n, const string& prod)
{
    nr = n;
    producer = prod;
}

void Car::display() const
{
    cout << "\n---------------------------- "
         << "\nCar number:    " << nr
         << "\nProducer:      " << producer
         << endl;
}


// -------------------------------------------------------
// The methods of the derived class PassCar:

/*
// First version of the constructor of PassCar
// ----------------------------------------------------
PassCar::PassCar(const string& tp, bool sr, long n,
                 const string& prod)
{
    setNr(n);              // Initial values for data
    setProd(prod);         // elements of the baseclass.

    PassCarType  = tp;     // Initial values for data ele-
    sunRoof = sr;          // ments of the derived class
} 

// Second version of the constructors of PassCar
// ----------------------------------------------------
PassCar::PassCar(const string& tp, bool sr, long n, 
                 const string& prod) : Car( n, prod)
{
    PassCarType  = tp;  // Initial values for data ele-
    sunRoof = sr;       // ments of the derived class
}
*/

// Third version of the constructor of PassCar
// ----------------------------------------------------
PassCar::PassCar(const string& tp, bool sr, long n, 
                 const string& prod)
       : Car( n, prod), passCarType(tp), sunRoof(sr) 
{
   // Here remains nothing to do
}

void PassCar::display( void) const
{
   Car::display();            // Method in base class
   cout <<   "Type:          " << passCarType
        << "\nSunroof:       ";  
   if(sunRoof)
       cout << "yes "<< endl;
   else
       cout << "no " << endl;
}
