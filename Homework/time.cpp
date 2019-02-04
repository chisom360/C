/* mktime example: weekday calculator */
#include <stdio.h> /* printf, scanf */
#include <time.h>
#include <iostream> /* time_t, struct tm, time, mktime */

int main()
{
    time_t rawtime;
    struct tm *timeinfo;
    /* get current timeinfo and modify it to the user's choice */
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    /*timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = 10;
    timeinfo->tm_min = 5;/*

    /* call mktime: timeinfo->tm_wday will be set */
    //mktime(timeinfo);

    printf("hour: %d\n", timeinfo->tm_hour);
    printf("min: %d\n", timeinfo->tm_min);
    printf("seconds: %d\n", timeinfo->tm_sec);

    return 0;
}