// ------------------------------------------------------
// city.h : Defines the class CityCar
// ------------------------------------------------------

#ifndef _CITY_H_
#define _CITY_H_

#include "car.h"

class CityCar
{
  private:
    Car* vp[100];
    int cnt;

  public:
    CityCar(){ cnt = 0;}
    ~CityCar();

    bool insert(const string& tp, bool sr,
                long n, const string& prod);
    bool insert(int a, double t,
                long n, const string& prod);  

    void display() const;
};

#endif  // _CITY_H
