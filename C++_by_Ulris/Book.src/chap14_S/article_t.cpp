// ------------------------------------------------------
// article_t.cpp 
// Tests the Article class.
// ------------------------------------------------------

#include "article.h"      // Definition of the class
#include <iostream>
#include <string>
using namespace std;

void test();

// -- Creats and destroys objects of Article class -- 
Article Article1( 1111,"volley ball", 59.9);

int main()
{
   cout << "\nThe first statement in main().\n" << endl;

   Article Article2( 2222,"gym-shoes", 199.99);

   Article1.print();
   Article2.print();

   Article& shoes = Article2;          // Another name
   shoes.setNr( 2233);
   shoes.setName("jogging-shoes");
   shoes.setSP( shoes.getSP() - 50.0); 

   cout << "\nThe new values of the shoes object:\n";
   shoes.print();

   cout << "\nThe first call to test()." << endl; 
   test();
   cout << "\nThe second call to test()." << endl;
   test();

   cout << "\nThe last statement in main().\n" << endl; 

   return 0; 
}

void test()
{
   Article shirt( 3333, "T-Shirt", 29.9);
   shirt.print();

   static Article net( 4444, "volley ball net", 99.0);
   net.print();

   cout << "\nLast statement in function test()"
        << endl;
}
