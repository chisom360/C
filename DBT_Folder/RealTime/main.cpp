#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "RealTime.h" // include definition of class RealTime from RealTime.h
using namespace std;
#include <time.h>

int main()
{
    RealTime timeobj;

    cout << timeobj.setRealHour();

    return 0;
}