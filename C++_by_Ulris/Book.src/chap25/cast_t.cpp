// cast_t.cpp
// Dynamic Casts in class hierarchies.
// ----------------------------------------------------

#include "car.h"

bool inspect( PassCar* ),       // Inspection of different
     inspect( Truck* );         // car types.

bool separate(Car* );           // To separate cars 
                                // for inspection.
int main()
{
    Car*   carPtr   = new PassCar("520i", true,3265, "BMW");
    Truck* truckPtr = new Truck(8, 7.5, 5437, "Volvo");

    // ... to test some casts and ...
    separate(carPtr);
    separate(truckPtr);
    
    return 0;
}

bool separate( Car* carPtr) 
{
   PassCar* passCarPtr = dynamic_cast<PassCar*>(carPtr);
   if( passCarPtr != NULL)
      return inspect( passCarPtr);
   
   Truck* truckPtr = dynamic_cast<Truck*>(carPtr);
   
   if( truckPtr != NULL)
      return inspect( truckPtr);
   return false;
}

bool inspect(PassCar* passCarPtr)
{
    cout << "\nI inspect a passenger car!";
    cout << "\nHere it is:";
    passCarPtr->display();
   
    return true;
}

bool inspect(Truck* truckPtr)
{
    cout << "\nI inspect a truck!";
    cout << "\nHere it is:";
    truckPtr->display();
    
    return true;
}
