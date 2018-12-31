#ifndef __LOGMAN_H__
#define __LOGMAN_H__

#include "log.h"
#include "fenced.h"

namespace LogMan
{
    enum TEnabler {NOT_INIT = -2, DEFAULT, DISABLED, ENABLED};
    void Init(TEnabler& enabler, const char* pFile, int line);
    void Set(const char* pFile, int line, TEnabler enabler);
    bool LogEnabled(TEnabler& enabler, const TLogLevel& level, const char* pFile, int line);
}

#define LOGMAN(level) \
    if (bool alreadyLogged = false); \
    else for (static LogMan::TEnabler enabler = LogMan::NOT_INIT; \
                 !alreadyLogged && LogMan::LogEnabled(enabler, level, __FILE__, __LINE__); alreadyLogged = true) \
             FILELog().Set(__FILE__, __LINE__).Get(level)

#endif
