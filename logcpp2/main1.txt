#include "logman.h"

int main(int argc, char* argv[])
{
    FILELog::ReportingLevel() = logDEBUG;
    const int count = 3;
    LogMan::Set("main1.cpp", 13, LogMan::DISABLED);
    LogMan::Set("main1.cpp", 14, LogMan::DISABLED);
    LogMan::Set("main1.cpp", 14, LogMan::ENABLED);
    LOGMAN(logDEBUG) << "A loop with " << count << " iterations";
    for (int i = 0; i != count; ++i)
    {
        LOGMAN(logINFO) << "you won't see this message; the counter i = " << i; // line 13
        LOGMAN(logDEBUG2) << "this one is visible; the counter i = " << i; // line 14
        LOGMAN(logINFO) << "you will see this one just once; the counter i = " << i; //line 15
        LogMan::Set("main1.cpp", 15, LogMan::DISABLED);
    }
    return 0;
}
/*
Simple test app that uses the LOGMAN's interface.
However this is NOT a good usage of the LOGMAN.

It is very fragile when changing of source code; when
it is acceptable to change the source code is is better 
to directly change the log level instead of using this mechanism.
*/
