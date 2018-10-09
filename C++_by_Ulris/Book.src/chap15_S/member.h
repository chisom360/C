// ------------------------------------------------------
// member.h 
// Defines the Member class containing a constant 
// and a static member.
// ------------------------------------------------------
#ifndef _MEMBER_H_
#define _MEMBER_H_

#include "Date.h"
#include <string>
using namespace std;

class Member
{
  private: 
    int nr;                       // Member number
    string name;                  // Name
    const Date birth;             // Birthday
    // ... other datas

    static Member *ptrBoss;       // Pointer to boss,
                                  // NULL = no boss.
  public:
    Member( long m_nr, const string& m_name, 
              const Date& m_birth)
    : nr(m_nr), birth(m_birth)
    {
       if( !setName(m_name))  name = "Unknown";
    }

    Member( long m_nr, const string& m_name,
              int day, int month, int year)
    : nr(m_nr), birth(day,month,year)
    {
        if( !setName(m_name))  name = "Unknown";
    }

    int           getNr()    const { return nr; }
    const string& getName()  const { return name; }
    const Date&  getBirthday() const { return birth; }
 
    void setNr( int n) { nr = n; }

    bool setName( const string& s)
    {
       if( s.size() < 1)           // No empty name
         return false;
       name = s;
       return true; 
    }

    void display() const;

    // static methods:
    static Member* getBoss()
    {
        return ptrBoss;
    }
    
    static void setBoss( Member* ptrMem) 
    {
       ptrBoss = ptrMem;
    }
};

#endif   // _MEMBER_H_


