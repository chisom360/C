// ------------------------------------------------------
// motorHome_t.cpp
// Testing the multiply-derived class MotorHome.
// ------------------------------------------------------

#include "motorHome.h"

int main()
{
    MotorHome rv(12345L, "Texaco", 2, 140.5, LUXURY);
    rv.display();

    MotorHome holiday;
    holiday.display();          // Default values
    cin.get();  
 
    holiday.setNr(54321);
    holiday.setProd("VW");
    holiday.setRoom(1);
    holiday.setSquareFeet(110.5);
    holiday.setCategory(SECONDCLASS);

    holiday.display();

    return 0;
}
