// ----------------------------------------------------
// date.h 
// First Definition of class Date.
// ----------------------------------------------------

#ifndef _DATE_          // Avoid multiple inclusion.
#define _DATE_

class Date
{
  private:                       // Sheltered elements:
    short month, day, year;

  public:                       // Public interface:
    void init(void);
    void init( int month, int day, int year);
    void print(void);
};

#endif   //  _DATE_
