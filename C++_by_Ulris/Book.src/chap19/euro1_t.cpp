// Euro1_t.cpp 
// Tests the operators of class Euro.
// --------------------------------------------------------
#include "Euro1.h"              // Definition of the class
#include <iostream>
using namespace std;

int main()
{
   cout << "  * * *  Testing the class Euro  * * *\n" << endl;

   Euro wholesale( 20,50), retail;
   retail = wholesale;                  // Standard assignment
   retail += 9.49;                      // += (Euro)9.49

   cout << "Wholesale price: ";   wholesale.print(cout);
   cout << "Retail price:    ";   retail.print(cout);

   Euro discount( 2.10);                // double-constructor
   retail -= discount;
   cout << "\nRetail price including discount: ";
   retail.print(cout);

   wholesale = 34.10; 
   cout << "\nNew wholesale price: ";  wholesale.print(cout);

   Euro profit( retail - wholesale);    // Subtraction and
                                        // copy constructor
   cout << "\nThe profit: ";
   profit.print(cout);                  // Negative!

  return 0;
}
