// ------------------------------------------------------
// suv_t.cpp :  Tests the class SUV
// ------------------------------------------------------

#include "suv.h"

int main()
{
    SUV mobil("Bravada", true, 120345, "Oldsmobile", 350, 6);
    mobil.display();

    SUV trucky;
    trucky.display();

    trucky.setNr(543221);
    trucky.setProd("Renault");
    trucky.setCapacity(1000.0);

    trucky.display();

    return 0;
}
