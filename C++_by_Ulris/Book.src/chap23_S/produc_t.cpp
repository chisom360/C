// ------------------------------------------------------
// product_t.cpp
// Tests classes Product, PrepackedFood und FreshFood.
// ------------------------------------------------------

#include "product.h"

int main()
{
   Product p1(12345L, "Flour"), p2;

   p1.printer();             // Output the first product 
 
   p2.setName("Sugar");      // Set the data members
   p2.setCode(543221);

   p2.printer();            // Output the second product

                            // Prepacked products:
   PrepackedFood pf1(0.49, 23456, "Salt"), pf2;

   pf1.printer();           // Output the first 
                            // prepacked product
   cout << "\n Input data of a prepacked product: ";
   pf2.scanner();           // Input and output
   pf2.printer();           // data of 2nd product

   FreshFood pu1(1.5, 1.69, 98765, "Grapes"), pu2;

   pu1.printer();           // Output first item
                            // fresh food
   cout <<"\n Input fresh food data: ";
   pu2.scanner();           // Input and output 
   pu2.printer();           // data of 2nd product.

   cout << "\n-------------------------------"
        << "\n-------------------------------"
        << "\nAgain in detail: \n"
        << fixed << setprecision(2)
        << "\nBarcode:       " << pu2.getCode()
        << "\nName:          " << pu2.getName()
        << "\nPrice per Lbs: " << pu2.getPrice()
        << "\nWeight:        " << pu2.getWght()
        << "\nEnd price:     " << pu2.getPrice()
                                  * pu2.getWght()
        << endl;

   return 0;
}

