// ------------------------------------------------------
// date_t.cpp 
// Using objects of class Date.
// ------------------------------------------------------

#include "Date.h" 
#include <iostream>
using namespace std;

int main()
{
   Date  today, birthday( 1, 29, 1927);
   const Date d2010(1,1,2010);

   cout << "\nBrigit's birthday: "
        << birthday.asString() << endl;

   today.setDate();
   cout << "\nToday's date: " << today.asString()
        << endl;;

   if( today.isLess( d2010))
      cout << "Good luck for this decade \n"
           << endl;
   else
      cout << " See you next decade \n" << endl;

   Date holiday;
   int month, day, year;   char c;

   cout << "\nWhen does your next vacation begin?\n"
        << "Enter in Month-Day-Year format: ";
   
   if( !(cin >> month >> c >> day >> c >> year) )
      cerr << "Invalid input!\n" << endl;
   else if ( !holiday.setDate( month, day,  year))
      cerr << "Invalid date!\n" << endl;
   else
   {
      cout << "\nYour first vacation: ";
      holiday.print();

      if( today.getYear() < holiday.getYear())
         cout << "You should go on vacation this year!\n"
              << endl;
      else
         cout << "Have a nice trip!\n" << endl; 
   }
   return 0;
}
