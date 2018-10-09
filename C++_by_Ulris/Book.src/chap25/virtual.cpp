// virtual.cpp : Tests the virtual method display()
//               of the classes Car and PassCar.
// ---------------------------------------------------- 

#include "car.h" 

// The Car class with virtual method display():
// class Car
// {
//   ...
//   virtual void display() const;
// };

int main()
{
  Car* pCar[2];       // Two pointers to the base class.
  int i = 0;          // Index

  pCar[0] = new Car( 5634L, "Mercedes");
  pCar[1] = new PassCar("Meada",true,3421,"Mazda");
  pCar[2] = new Truck( 5, 7.5, 1234, "Ford");

  while( true)
  {
    cout << "\nTo output an object of type "
              "Car, PassCar or Truck!"
            "\n 1 = Car,  2 = PassCar,  3 = Truck"
            "\nYour input (break with 0): ";
    cin >> i;
    --i;
    if( i < 0  || i > 2)
      break;
    pCar[i]->display(); 
  }
  return 0;
}
