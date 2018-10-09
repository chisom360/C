// ------------------------------------------------------
// suv.h : Defines the class Van and
//         the multiply-derived class SUV
// ------------------------------------------------------
#ifndef _SUV_H
#define _SUV_H

#include "car.h" 

class Van : public virtual Car
{
  private:
    double capacity;

  public:
    Van(long n=0L, const string& prod="", double l=0.0)
    : Car(n,prod)  
    {
        if(l > 750)  l = 750;
        capacity = l; 
    }

    void setCapacity(double l)
    {
        if(l > 750)  
            capacity= 750;
        else
            capacity = l;
    }
    double getCapacity() const { return capacity; }

    void display() const
    {
       cout << "Capacity:         " 
            << capacity  << " kg" << endl;
    }
};

class SUV : public PassCar, public Van
{
  private:
    int cnt;          // Number of seats

  public:
     SUV(const string& tp="without type", bool sr=false,
         long n=0L, const string& prod="none", double l=0.0, int z = 1) 
    : PassCar(tp,sr), Car(n,prod), 
      Van(n,prod,l), cnt(z)
    { }

    void display() const
    {
       PassCar::display();
       Van::display();
       cout << "Number of seats:  " << cnt << endl;
    }
};

#endif
