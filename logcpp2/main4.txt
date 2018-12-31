#include <log.h>
#include <map>

enum TEnabler {DEFAULT = -1, DISABLED = 0, ENABLED = 1};
typedef std::pair<std::string, int> TEnablerKey;
typedef std::pair<TEnabler*, TEnabler> TEnablerValue;
typedef std::map<TEnablerKey, TEnablerValue> TEnablers;

TEnablers enablers;
TEnabler Init(TEnabler& enabler, const char* fileName, int line)
{
    return ENABLED;
}

int main(int argc, char* argv[])
{
    {
        static TEnabler enabler = Init(enabler, __FILE__, __LINE__);
        if ((enabler == DEFAULT && FILELog::ReportingLevel().Get() >= logINFO) || enabler == ENABLED)
            FILELog().Set(__FILE__, __LINE__).Get(logINFO) << "Hello World";
    }
    return 0;
}

/*
This is the basic structure later 'encapsulated' in a macro definition
*/
