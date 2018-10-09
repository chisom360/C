// ------------------------------------------------------
// city.cpp : Methods of class CityCar
// ------------------------------------------------------
#include "city.h"

CityCar::~CityCar()
{
   for(int i=0; i < cnt; ++i)
      delete vp[i];
}

// Insert a passenger car:
bool CityCar::insert(const string& tp, bool sr,
                     long n, const string& prod)
{
    if( cnt < 100)
    {
       vp[cnt++] = new PassCar( tp, sr, n, prod);
       return true;
    }
    else
        return false;
}


// Insert a truck:
bool CityCar::insert( int a, double t,
                      long n, const string& prod)  
{
   if( cnt < 100)
   {
       vp[cnt++] = new Truck( a, t, n, prod);
       return true;
    }
    else
        return false;
}

void CityCar::display() const
{
    cin.sync(); cin.clear();    // No previous inputs
    for(int i=0; i < cnt; ++i)
    {
       vp[i]->display();
       if((i+1)%4 == 0)  cin.get();
    }
}
