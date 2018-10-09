// ---------------------------------------------------
// member.cpp 
// Members of class Member not defined inline. 
// ---------------------------------------------------

#include "member.h"            // Class definition
#include <iostream>
using namespace std;

 // Pointer to the boss:
Member* Member::ptrBoss = NULL; 
                                   
void Member::display() const
{
   string line( 50, '-'); 
   cout << line
        << "\n  Member number: " << nr
        << "\n  Member:        " << name 
        << "\n  Birthday       " << birth.asString()
        << '\n' << line << endl;
}
