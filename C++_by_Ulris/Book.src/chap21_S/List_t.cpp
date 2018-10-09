// -------------------------------------------------------
//  List_t.cpp
//  Tests the List class.
// -------------------------------------------------------

#include "List.h"

int main()
{
   cout << "\n * * *  Testing the class list  * * *\n"
        << endl;
    
   List  aList;               // A list 

   cout << aList << endl;     // List is still empty.

   cout << "\nEnter account changes (Date and Amount)"
           "\n(Type invalid input to quit, e.g. q):\n";
   Date date;
   int month, day, year;   char c;
   double amount;

   while( true)
   {
     cout << "Date format Month-Day-Year : ";
     if( !(cin >> month >> c >> day >> c >> year)
         || ! date.setDate( month, day, year) )
     break;                            // Invalid date.
     
     cout << "Account change: ";
     if( !(cin >> amount) ) break;
     
     aList.pushBack( date, amount);
   }

   cout << "\nContent of the list:\n";
   cout << aList << endl; 

   cout << "\nRemoving the first element of the list:\n";

   ListEl *ptrEl = ptrEl = aList.front();
   if( ptrEl != NULL)
   {
      cout << "Deleting:  " << *ptrEl << endl;
      aList.popFront();
   }

   cout << "\nContent of the list:\n";
   cout << aList << endl; 

   return 0;
} 
