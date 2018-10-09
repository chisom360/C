// --------------------------------------------------
// car.h:   Definition of baseclass Car and
//          of the derived class PassCar 
// --------------------------------------------------
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
                                   // Access methods:
    long  getNr(void) const { return nr; }
    void  setNr( long n ) { nr = n; }

    const string& getProd() const{ return producer; }
    void  setProd(const string& p){ producer = p; }

    void display( void ) const;    // Display a car
};

class PassCar : public Car         // Derived class
{
  private:
    string passCarType;
    bool   sunRoof;

  public:                           // Constructor:
    PassCar( const string& tp, bool sr,
             long n = 0 , const string& prod = "");
                                    // Access methods:
    const string& getType() const{ return passCarType; }
    void  setType( const string s) { passCarType = s; }

    bool  getSunRoof() const   { return sunRoof; }
    void  setSunRoof( bool b ) { sunRoof = b; }

    void  display() const;
};

#endif // _CAR_H_
