// car_t.cpp:  Testing the base class Car and
//             the derived class PassCar.
// ----------------------------------------------------- 
#include "car.h"

int main()
{
    const PassCar beetle("Beetle", false, 3421L, "VW");
    beetle.display();  

    cout << "\nAnd the passenger car number again: " 
         << beetle.getNr() << endl;

    PassCar cabrio("Carrera", true);
    cabrio.setNr(1000L); 
    cabrio.setProd("Porsche");
    cabrio.display();

    cout << "\nOnly data of the base class: ";
    cabrio.Car::display();

    return 0;
}
