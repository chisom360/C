//  Solution of Exercise 1 (Chapter 7)
//  Testing macros of myMacro.h
//  --------------------------------------------------
//  To activate the control characters,
//  a corresponding screen driver must be loaded.
//  Under Windows 9x this is done by the 
//  following line contained in file CONFIG.SYS:
//         DEVICE=C:\Windows\Command\Ansi.sys
//  --------------------------------------------------

#include <iostream>
using namespace std;

#include "myMacros.h"

int main()
{
   COLOR( WHITE, BLUE);
   CLS;

   LOCATE(5,20);
   cout << "\aGood Morning" << endl;

   LOCATE(10,1);
   COLOR( YELLOW, BLUE);
   cout << "Enter two different numbers:\n";
   
   double x = 0.0,  y = 0.0;
   if( !(cin >> x && cin >> y) ) // If the input was
   {                             // invalid.
      INVERS;
      cout << "\nInvalid input!" << endl;
      NORMAL;
      return 1;
   }

   NORMAL;

   cout << "\n ABS(x)    : " << ABS(x)
        << "\n MIN(x, y) : " << MIN(x, y)
        << "\n MAX(x, y) : " << MAX(x, y) << endl;

   return 0;
}
