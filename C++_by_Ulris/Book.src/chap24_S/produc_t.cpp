// ------------------------------------------------------
// produc_t.cpp
// Tests up  and down Casts for the classes
// Product, PrepackedFood and FreshFood.
// ------------------------------------------------------

#include "product.h"

const Product& isLowerCode(const Product& p1,
                           const Product& p2);

int main()
{
   Product* pv[3];
   FreshFood* pu;

   pv[0] = new Product(12345L, "Flour");
   pv[1] = new PrepackedFood(0.49, 23456, "Salt");
   pv[2] = new FreshFood(1.5, 1.69, 98765, "Grapes");

   pu =  new FreshFood(2.5, 2.69, 56789, "Peaches");
  
   cout << "\nA fresh product: ";
   pu->printer();

   cout << "\nThe generic data of the other products:";
   int i;
   for(i=0; i < 3; ++i)
       pv[i]->printer();

   cout << "\nGo on with return! ";
   cin.get();

   cout << "\nAnd now the downcast: " << endl;
   static_cast<PrepackedFood*>(pv[1])->printer();
   static_cast<FreshFood*>(pv[2])->printer();

   cout << "\nGo on with return! ";
   cin.get();

   cout << "\nAnd an upcast: " << endl;
   static_cast<Product*>(pu)->printer();

   cout << "\nNow compare the barcodes!" << endl;

   cout << "\nIs barcode for flour or salt smaller?";
   isLowerCode(*pv[0], *pv[1]).printer();
   
   cout << "\nIs barcode for salt or grapes smaller?";
   isLowerCode(*pv[1], *pv[2]).printer();

   return 0;
}

const Product& isLowerCode(const Product& p1, 
                           const Product& p2)
{
    if(p1.getCode() < p2.getCode())
        return p1;
    else 
        return p2;
}

