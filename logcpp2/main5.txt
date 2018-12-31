#include <log.h>
#include <map>

enum TEnabler {DEFAULT = -1, DISABLED = 0, ENABLED = 1};
typedef std::pair<std::string, int> TEnablerKey;
typedef std::pair<TEnabler*, TEnabler> TEnablerValue;
typedef std::map<TEnablerKey, TEnablerValue> TEnablerMap;

TEnablerMap enabler;
TEnabler Init(TEnabler& enabler, const char* fileName, int line)
{
    return ENABLED;
}

#define LOGMAN(level) \
    if (bool alreadyLogged = false); \
    else for (static TEnabler enabler = Init(enabler, __FILE__, __LINE__); \
                 !alreadyLogged && enabler == DEFAULT && FILELog::ReportingLevel().Get() >= level; alreadyLogged = true) \
             FILELog().Set(__FILE__, __LINE__).Get(level)

int main(int argc, char* argv[])
{
    LOGMAN(logINFO) << "Hello world!";
    return 0;
}
/*
Simple prototype using dynamic static variable initialization; this is dafe in C++0x but it would fail in current C++
*/
