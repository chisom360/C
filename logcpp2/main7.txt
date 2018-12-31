#include <log.h>

enum TEnabler {NOT_INIT = -2, DEFAULT, DISABLED, ENABLED};

void Init(int& enabler)
{
    //...
}

bool LogEnabled(int& enabler, const TLogLevel& level)
{
    AO_t value = AO_load_read(reinterpret_cast<AO_t*>(&enabler));
    int safeEnabler = reinterpret_cast<int&>(value);
    if (safeEnabler == NOT_INIT)
    {
        Init(enabler);    
        value = AO_load_read(reinterpret_cast<AO_t*>(&enabler));
        safeEnabler = reinterpret_cast<int&>(value);    
    }
    return Output2FILE::Stream().Get() && ((safeEnabler == DEFAULT && FILELog::ReportingLevel().Get() >= level) || safeEnabler == ENABLED);
}

#define LOGMAN(level) \
    if (bool alreadyLogged = false); \
    else for (static int enabler = NOT_INIT; !alreadyLogged && LogEnabled(enabler, level); alreadyLogged = true) \
             FILELog().Set(__FILE__, __LINE__).Get(level)

int main(int argc, char* argv[])
{
    LOGMAN(logINFO) << "Hello world!";
    return 0;
}
/*
Prototype using the atomic ops library
*/
