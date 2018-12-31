#include "logman.h"

void foo(int i)
{
    LOGMAN(logINFO) << i; LOGMAN(logINFO) << i; //line 5
}

template <typename T>
void bar(const T& t)
{
    LOGMAN(logINFO) << t; // line 11
}

int main(int argc, char* argv[])
{
    FILELog::ReportingLevel().Set(logDEBUG);
    LogMan::Set("main6.cpp", 5, LogMan::ENABLED);
    foo(1);
    LogMan::Set("main6.cpp", 5, LogMan::DISABLED);

    LogMan::Set("main6.cpp", 11, LogMan::ENABLED);
    bar(1.2);
    bar(1);
    bar(argv);
    LogMan::Set("main6.cpp", 11, LogMan::DISABLED);
    bar(argv);
    return 0;
}
/*
Test for having multiple static variable on the same line:
    a) because we use multiple log statements on the same line (foo())
    b) because we log from a template function (bar())
*/
