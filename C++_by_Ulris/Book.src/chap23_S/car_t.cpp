// ----------------------------------------------------- 
// Car_t.cpp : Tests the baseclass Car and
//             the derived classes PassCar and Truck.
// ----------------------------------------------------- 
#include "car.h"

int main()
{
    Truck toy(5, 7.5, 1111, "Volvo");
    toy.display();

    char c;
    cout << "\nDo you want to create an object of type PassCar? (y/n) ";
    cin >> c;
    
    if( c == 'y' || c == 'Y')
    {
       const PassCar beetle("Beetle", false, 3421, "VW");
       beetle.display();  
    }

    cout << "\nDo you want to create an object of type Car? (y/n) ";  
    cin >> c;
    
    if( c == 'y' || c == 'Y')
    {
       const Car oldy(3421, "Rolls Royce");
       oldy.display();  
    }
    
    return 0;
}
