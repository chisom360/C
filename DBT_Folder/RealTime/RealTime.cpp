#include "RealTime.h"
//#include "../RTOS/RTOS_Handler.h"
#include "RTOS_Handler.h"

RealTime::RealTime()
{
    t.setHour(RTOS_Hour());
    t.setMinute(RTOS_MINUTES());
    t.setSecond(RTOS_SECONDS());
    t.setDay(getDayOfTheWeek());
}

int RealTime::getRealTimeHour()
{
    return t.getHour();
}

int RealTime::getRealTimeMinutes()
{
    return t.getMinute();
}

int RealTime::getRealTimeSeconds()
{
    return t.getSecond();
}

int RealTime::getRealDay()
{
    return t.getDay();
}
