// ------------------------------------------------------
// car.cpp
// Implements the methods of Car, PassCar  and Truck
// ------------------------------------------------------
#include "car.h"

// ------------------------------------------------------
// The methods of base class Car:

Car::Car( long n, const string& prod)
{
    cout << "Creating an object of type Car." << endl;
    nr = n;
    producer = prod;
}

Car::~Car()
{
    cout << "Destroying an object of type Car" << endl;
}

void Car::display() const
{
    cout << "\n---------------------------- "
         << "\nCar number:   " << nr
         << "\nProducer:     " << producer
         << endl;
}


// -------------------------------------------------------
// The methods of the derived class PassCar:

PassCar::PassCar(const string& tp, bool sr, long n, const string& prod)
       : Car( n, prod), passCarType( tp ), sunRoof( sr ) 
{
   cout << "Creating an object of type PassCar." << endl;
}

PassCar::~PassCar()
{
    cout << "\nDestroying an object of type PassCar" << endl; 
}

void PassCar::display( void) const
{
    Car::display();            // Base class method 

    cout <<   "Type:         " << passCarType
         << "\nSunroof:      ";  
    if(sunRoof)
       cout << "yes "<< endl;
    else
       cout << "no " << endl;
}


// ----------------------------------------------------
// The methods of the derived class Truck:

Truck::Truck( int a, double t, long n, const string& prod)
     : Car( n, prod), axles(a), tons(t) 
{
   cout << "Creating an object of type Truck." << endl;
}

Truck::~Truck()
{
    cout << "\nDestroying an object of type Truck\n";
}
void Truck::display() const
{
    Car::display();
    cout <<   "Axles:        " << axles
         << "\nCapacity:     " << tons << " long tons\n";
}
