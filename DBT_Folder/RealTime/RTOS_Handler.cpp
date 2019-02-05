#include "RTOS_Handler.h"
#include <ctime>

int RTOS_Hour()
{
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    return timePtr->tm_hour;
}

int RTOS_MINUTES()
{
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    return timePtr->tm_min;
}

int RTOS_SECONDS()
{
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    return timePtr->tm_sec;
}

//Mon = 1. TUE = 2, Wed = 3, THUR = 4, FRI = 5
//SAT = 6, SUN = 7
int getDayOfTheWeek()
{
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    return timePtr->tm_wday;
}
