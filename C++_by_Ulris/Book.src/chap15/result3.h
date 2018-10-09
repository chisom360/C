// result3.h
// The class Result with static data members.
// ---------------------------------------------------

#ifndef  _RESULT_
#define  _RESULT_
#include "DayTime.h"            // Class DayTime

class Result
{
  private:
    double val;
    const  DayTime time;
  
    // Declaration of static elements:
    static double min, max;    // Minimum, maximum
    static bool first;         // true, if it is the first value.
    static void setMinMax(double w);   // private function
  
  public:
    Result(double w, const DayTime& z = currentTime());
    Result(double w, int hr, int min, int sec);
 
    double getVal() const { return val; }
    const DayTime& getTime() const  { return time; }

    void setVal( double w )
    { 
      val = w;
      setMinMax(w);
    }
    void print() const;

    static double getMin() { return min; }
    static double getMax() { return max; }
};

#endif  //  _RESULT_ 
