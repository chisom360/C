// ------------------------------------------------------
// counter.cpp : Simulates a checkout desk
// ------------------------------------------------------
#include "product.h"

void record(); 

int main()
{
   cout << "\nHere is a checkout desk!" << endl;

   char c;
   while(true)
   {
       cin.sync();
       cout << "\nAnother customer (y/n)?   "; 
       cin  >> c;

       if(c == 'y' || c == 'Y')
           record();
       else 
           break;
   }
   return 0;
}


// ------------------------------------------------------
// record() : Records the articles bought by a customer 
//            and the total price.
void record()
{
   Product* v[100];
   int x, i, cnt = 0;
   double sum = 0.0;

   for (i = 0; i < 100; i++)
   {
      cin.sync();
      cout << "\nWhat is the next article?" << endl;
      cout << "  0 = No more article\n"
           << "  1 = Fresh Food\n"
           << "  2 = Pre-packed article\n"
           << "? " ;
      cin  >> x;
      
      if( x <= 0 || x >= 3) 
          break;
 
      switch(x)
      {
        case 2:
            v[i] = new PrepackedFood;
            v[i]->scanner();
            sum += ((PrepackedFood*)v[i])->getPrice();
            break;

        case 1:
           v[i] = new FreshFood;
           v[i]->scanner();
           sum += ((FreshFood*)v[i])->getPrice() 
                  * ((FreshFood*)v[i])->getWght();
           break;
      }
   }

   cnt = i;
   for( i=0; i < cnt; i++)           // Output
      v[i]->printer();

   cout << "\n-----------------------------"
        << fixed << setprecision(2)
        << "\nTotal price:       " << sum << endl;
}
