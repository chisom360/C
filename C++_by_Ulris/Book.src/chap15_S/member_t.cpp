// ----------------------------------------------------
// member_t.cpp 
// Using the class Member.
// ----------------------------------------------------
#include "Member.h"        // Class definition
#include <iostream>
#include <string>
using namespace std;

int main()
{
   Date today;  today.setDate();

   cout << "Date: " << today.asString() << endl;

   Member fran( 0, "Quick, Fran", 17,11,81),
          kurt( 2222, "Rush, Kurt", Date(3,5,77) );
   fran.setNr(1111);

   cout << "\nTwo members of the sports club:" << endl;
   fran.display();
   kurt.display();

   cout << "\nSomething changed!" << endl;
   fran.setName("Rush-Quick");
   fran.display();
   
   Member benny( 1122,"Rush, Benny", 1,1,2000);
   cout << "The youngest member of the sports club: \n";
   benny.display();

   // Who is the boss? 
   int nr;
   Member *ptr = NULL;
   cout << "\nWho is the boss of the sports club?\n"
        << "Enter the member number: ";
   if( cin >> nr)
   {
      if( nr == fran.getNr())
         ptr = &fran;  
      else if( nr == kurt.getNr())
         ptr = &kurt;  
      Member::setBoss( ptr);
   }
   cout << "\nThe Boss of the sports club:" << endl;
   ptr = Member::getBoss();
   if( ptr != NULL)
      ptr->display();
   else
      cout << "No boss existing!" << endl;
   return 0; 
}
