#include <iostream>
#include <ctime>
#include "RTOS_Handler.h"
using namespace std;

int main()
{
    cout << "Hour: " << RTOS_Hour() << endl;
    cout << "Minutes: " << RTOS_MINUTES() << endl;
    cout << "Seconds: " << RTOS_SECONDS() << endl;

    return 0;
}
