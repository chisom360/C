// ----------------------------------------------------
// date_t.cpp 
// Using objects of class Date.
// ----------------------------------------------------

#include "date.h" 
#include <iostream>
using namespace std;

int main()
{
   Date today, birthday, aDate;

   today.init();
   birthday.init( 12, 11, 1997);

   cout << "Today's date: ";
   today.print();
   
   cout << "\n Felix' birthday: ";
   birthday.print();

   cout << "----------------------------------\n"
           "Some testing outputs:" << endl;

   aDate = today;                 // Assignment ok
   aDate.print();

   Date *pDate = &birthday;       // Pointer to birthday
   pDate->print();
  
   Date &holiday = aDate;         // Reference to aDate.
   holiday.init( 1, 5, 2000);     // Writing to aDate.
   aDate.print();                 // holiday.print();

   return 0;
}
