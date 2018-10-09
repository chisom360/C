// ----------------------------------------------------
// car.h :  Defines the base class Car and
//          the derived classes PassCar and Truck
// --------------------------------------------------------
#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <string>
using namespace std;

class Car                          // Base class
{
  private:
    long   nr;
    string producer;

  public:                          // Constructor:
    Car( long n = 0L, const string& prod = "");
    virtual ~Car();                // Destructor

                                   // Access methods:
    long  getNr(void) const { return nr; }
    void  setNr( long n ) { nr = n; }

    const string& getProd() const{ return producer; }
    void  setProd(const string& p){ producer = p; }

    virtual void display( void ) const;  // Display a car
};

class PassCar : public virtual Car         // Derived class
{
  private:
    string passCarType;
    bool   sunRoof;

  public:                           // Constructor:
    PassCar( const string& tp, bool sr,
             long n = 0L , const string& prod = "");
    ~PassCar();                     // Destructor

                                    // Access methods:
    const string& getType() const{ return passCarType; }
    void  setType( const string s) { passCarType = s; }

    bool  getSunRoof() const   { return sunRoof; }
    void  setSunRoof( bool b ) { sunRoof = b; }

    void  display() const;
};
 

class Truck : public virtual Car
{
  private:
    int    axles;          // Number of axles
    double tons;           // Load capacity
 
  public:
    Truck( int a, double t, long n = 0L, const string& prod = "");
    ~Truck();

    void   setAxles(int a){ axles = a;}
    int    getAxles() const  { return axles; }

    void   setCapacity( double t) { tons = t;}
    double getCapacity() const    { return tons; }

    void display() const;
};

#endif // _CAR_H_
