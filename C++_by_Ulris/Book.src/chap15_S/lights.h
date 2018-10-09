// lights.h 
// Uses enum-constants within a class.
// ---------------------------------------------------
#include <iostream>
using namespace std;

class Lights
{
  public:             // Enumeration for class Lights
    enum State { off, red, green, yellow };

  private:
    State state;

  public:
    Lights( State s = off) : state(s) {}
    State getState() const {  return state; }
    void setState( State s)
    {
       switch(s)
       { case off:    cout << "    OFF      ";  break;
         case red:    cout << "    RED      ";  break;
         case green:  cout << "    GREEN    ";  break;
         case yellow: cout << "    YELLOW   ";  break;
         default:     return; 
       }
       state = s;
    }
};
 
 