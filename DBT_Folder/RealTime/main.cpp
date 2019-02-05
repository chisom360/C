#include <iostream>
#include "RealTime.h" // include definition of class RealTime from RealTime.h
using namespace std;

int main()
{
    RealTime timeobj;
    cout << "Hour: " << timeobj.getRealTimeHour() << endl;
    cout << "Minutes: " << timeobj.getRealTimeMinutes() << endl;
    cout << "Seconds: " << timeobj.getRealTimeSeconds() << endl;
    cout << "Day: " << timeobj.getRealDay() << endl;
    timeobj.t.printStandard();
    cout << '\n';
    return 0;
}