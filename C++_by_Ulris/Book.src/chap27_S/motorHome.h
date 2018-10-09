// ------------------------------------------------------
// motorHome.h : Definition of the class Home and the 
//               multiply-derived class MotorHome
// ------------------------------------------------------
#ifndef _MOTORHOME_H_
#define _MOTORHOME_H_

#include "car.h"

#include <iomanip>
#include <iostream>
using namespace std;

enum CATEGORY {LUXURY, FIRSTCLASS, SECONDCLASS, ECONOMY};

class Home
{
   private:
      int room;         // Number of rooms
      double ft2;       // Size

   public:
      Home(int r = 0, double f2 = 0.0)
      { room = r; ft2 = f2;}

      void setRoom(int n)  { room = n;}
      int  getRoom() const { return room; }

      void   setSquareFeet(double f2){ ft2 = f2;}
      double getSquareFeet() const   { return ft2; }

      void display() const 
      { 
         cout <<   "Number of rooms: " << room
              << "\nSquare feet:     " 
              << fixed << setprecision(2) << ft2 << endl;
      }
};

class MotorHome : public Car, public Home
{
   private:
      CATEGORY cat;

   public:
      MotorHome( long n=0L, const string& prod="", int ro=0,
                 double ft2=0.0, CATEGORY c=ECONOMY)
      : Car(n, prod), Home(ro, ft2), cat(c)
      {}

      void      setCategory(CATEGORY c){cat = c;}
      CATEGORY  getCategory() const { return cat;}

      void display() const
      {
         cout << "\nMotorHome:   ";
         Car::display();
         Home::display();
         cout << "Category:     ";
         switch(cat)
         {
            case LUXURY:      cout << "   Luxury";
                              break;
            case FIRSTCLASS:  cout << "   First class";
                              break;
            case SECONDCLASS: cout << "   Second class";
                              break;
            case ECONOMY:     cout << "   Economy";
                              break;
         }
         cout << endl;
     }
};

#endif
