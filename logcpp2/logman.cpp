#include "logman.h"
#include <map>
#include <vector>
#include <fstream>
#include <boost/thread/mutex.hpp>
#include <boost/static_assert.hpp>

namespace LogMan
{
typedef std::pair<std::string, int> TKey;
typedef std::vector<TEnabler *> TPtrLevels;

typedef std::pair<TPtrLevels, TEnabler> TValue;
typedef std::map<TKey, TValue> TMap;

TMap &GetMap()
{
    static TMap m;
    return m;
}

boost::mutex &GetMutex()
{
    static boost::mutex m;
    return m;
}

std::string ToString(TEnabler enabler)
{
    if (enabler == ENABLED)
        return "ENABLED";
    if (enabler == DISABLED)
        return "DISABLED";
    if (enabler == DEFAULT)
        return "DEFAULT";
    if (enabler == NOT_INIT)
        return "NOT_INIT";
    throw std::logic_error("Invalid value");
    return "";
}

TEnabler Read(TEnabler &enabler)
{
    BOOST_STATIC_ASSERT(sizeof(AO_t) == sizeof(TEnabler));
    AO_t value = AO_load_acquire_read(reinterpret_cast<AO_t *>(&enabler));
    return reinterpret_cast<TEnabler &>(value);
}

void Write(TEnabler src, TEnabler &dest)
{
    AO_store_release_write(reinterpret_cast<AO_t *>(&dest), reinterpret_cast<AO_t &>(src));
}

void Init(TEnabler &enabler, const char *pFile, int line)
{
    boost::mutex::scoped_lock l(GetMutex());
    TKey key = std::make_pair(std::string(pFile), line);
    TMap::iterator i = GetMap().find(key);

    if (i != GetMap().end())
    {
        TValue &value = i->second;
        value.first.push_back(&enabler);
        Write(value.second, enabler);
        FILE_LOG(logDEBUG) << "Initialized the LogMan: '" << pFile << ":" << line << "' = '" << ToString(Read(enabler)) << "' (preset value)";
    }
    else
    {
        Write(DEFAULT, enabler);
        TPtrLevels levels;
        levels.push_back(&enabler);

        GetMap()[key] = std::make_pair(levels, DEFAULT);
        FILE_LOG(logDEBUG) << "Initialized the LogMan for '" << pFile << ":" << line << "' = '" << ToString(DEFAULT) << "'";
    }
}

void Set(const char *pFile, int line, TEnabler enabler)
{
    boost::mutex::scoped_lock l(GetMutex());
    TKey key = std::make_pair(std::string(pFile), line);
    TMap::iterator i = GetMap().find(key);

    if (i != GetMap().end())
    {
        TValue &value = i->second;
        FILE_LOG(logDEBUG) << "Changing the value in LogMan: '" << pFile << ":" << line << "' = '" << ToString(enabler) << "' (old value = '" << ToString(value.second) << "')";
        value.second = enabler;
        TPtrLevels &levels = value.first;
        for (TPtrLevels::iterator j = levels.begin(); j != levels.end(); ++j)
        {
            Write(enabler, **j);
            FILE_LOG(logDEBUG) << "Set the LogMan (initialized value): '" << pFile << ":" << line << "' = '" << ToString(enabler) << "'";
        }
    }
    else
    {
        GetMap()[key] = std::make_pair(TPtrLevels(), enabler);
        FILE_LOG(logDEBUG) << "Saved the value in LogMan (add to the map): '" << pFile << ":" << line << "' = '" << ToString(enabler) << "'";
    }
}

bool LogEnabled(TEnabler &enabler, const TLogLevel &level, const char *pFile, int line)
{
    TEnabler safeEnabler = Read(enabler);
    if (safeEnabler == NOT_INIT)
    {
        // usleep(1000); //to test the race condition (Init() called multiple times)
        Init(enabler, pFile, line);
        safeEnabler = Read(enabler);
    }
    return ((safeEnabler == DEFAULT && FILELog::ReportingLevel().Get() >= level) || safeEnabler == ENABLED);
}
} // namespace LogMan
