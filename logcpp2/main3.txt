#include "logman.h"

int main(int argc, char* argv[])
{
    LogMan::Set("main3.cpp", 15, LogMan::DISABLED);
    const int count = 100000000;
    FILE_LOG(logINFO) << "Start file log";
    for (int i = 0; i != count; ++i)
    {
        FILE_LOG(logDEBUG) << "this is not executed";
    }
    FILE_LOG(logINFO) << "Start log man";
    for (int i = 0; i != count; ++i)
    {
        LOGMAN(logINFO) << "this is disabled too";
    }
    FILE_LOG(logINFO) << "End";
    return 0;
}
/*
This is a benchmark test comparing the plain FILE_LOG against the LOGMAN
*/
