/* ctime example */
#include <stdio.h> /* printf */
#include <time.h>  /* time_t, time, ctime */
#include <unistd.h>
#include <iostream>
#include <ctime>

int main()
{
    //time_t rawtime;
    //time(&rawtime);
    //printf("The minute is: %s", rawtime->tm_hour);

    time_t t = time(NULL);
    struct tm *tmp = gmtime(&t);
    printf("hours is %d\n", tmp->tm_hour);

    return 0;
}

/*
I want to extract hours, minutes and seconds as integer values from a time_t value representing seconds since epoch.

The value for hours is not correct. Why?

#include <stdio.h>
#include <time.h>

#include <unistd.h>

int main()
{
    char buf[64];

    while (1) {
        time_t t = time(NULL);
        struct tm *tmp = gmtime(&t);

        int h = (t / 360) % 24;  
        int m = (t / 60) % 60;
        int s = t % 60;

        printf("%02d:%02d:%02d\n", h, m, s);

                strftime(buf, sizeof(buf), "%H:%M:%S\n", tmp);
        puts(buf);
        sleep(1);
    }
}
/*