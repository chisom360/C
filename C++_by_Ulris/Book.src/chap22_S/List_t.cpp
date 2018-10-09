// -------------------------------------------------------
//  List_t.cpp
//  Tests the class List with copy constructor and 
//  assignment.
// -------------------------------------------------------

#include "List.h"

int main()
{
   cout << "\n * * *  Testing the class List  * * *\n"
        << endl;
   List  list1;                 // A list 
   cout << list1 << endl;       // The list is still empty.

   Date date( 11,8,1999);       // Insert 3 elements.
   double amount( +1234.56);
   list1.pushBack( date, amount);

   date.setDate( 1, 1, 2002);
   amount = -1000.99;
   list1.pushBack( date, amount);

   date.setDate( 2, 29, 2000);
   amount = +5000.11;
   list1.pushBack( date, amount);
 
   cout << "\nThree elements have been inserted!"
           "\nContent of the list:" << endl;
   cout << list1 << endl; 

   cout << "Press return to continue! "; cin.get();

   List list2( list1); 
   cout << "A copy of the 1st list has been created!\n"
           "Contents of the copy:\n" << endl;
   cout << list2 << endl; 

   cout << "\nRemove the first element from the list:\n";

   ListEl *ptrEl = ptrEl = list1.front();
   if( ptrEl != NULL)
   {
      cout << "To be deleted:  " << *ptrEl << endl;
      list1.popFront();
   }
   cout << "\nContent of the list:\n";
   cout << list1 << endl; 

   list1 = list2;          // Reassign the copy.

   cout << "The copy has been assigned to the 1st list!\n"
           "Contents after assignment:\n" << endl;
   cout << list1 << endl; 

   return 0;
}
