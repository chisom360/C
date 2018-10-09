// Euro_t.cpp 
// Tests the operators of class Euro.
// --------------------------------------------------------

#include "Euro.h"               // Definition of the class
#include <iostream>
using namespace std;

int main()
{
   cout << "  * * *  Testing the class Euro  * * *\n" << endl;

   Euro wholesale( 20,50),
        retail;
   retail = wholesale;                  // Standard assignment
   retail += 9.49;                      // += (Euro)9.49

   cout << "Wholesale price: " << wholesale << endl;
   cout << "Retail price:    " << retail << endl;

   Euro discount( 2.10);                // double-constructor
   retail -= discount;

   cout << "\nRetail price including discount: "
        << retail << endl;

   // To test input:
   cout << "\nEnter new wholesale price!" << endl; 

   if( !(cin  >> wholesale))
     cerr << "Invalid input!" << endl;
   else
     cout << "\nNew wholesale price: " << wholesale << endl;

   Euro profit( retail - wholesale);    // Subtraction and
                                        // copy constructor
   cout << "\nThe profit: "
        << profit << endl;              // May be negative!

//  retail = wholesale + 10.55;         // ok!
   retail = 10.55 + wholesale;          // ok now, too!
   cout << "\nWholesale price + 10.55 = " << retail << endl;

// Multiplication und Division:  
   Euro result( retail * 0.075);
   cout << "\n 7,5% of the retail price: " << result << endl;

   result = 121 * wholesale;
   cout << "\nWholesale price of 121 pieces: " << result << endl;

   result = result /3.0;
   cout << "\n1/3 of that: " << result << endl;

   return 0;
}
