// ------------------------------------------------------
// article_t.cpp 
// Tests the class Article including a copy constructor.
// ------------------------------------------------------

#include "article.h"           // Definition of the class

#include <iostream>
#include <string>
using namespace std;

void test( Article a);                      // Prototype

Article article1( 1111,"tent", 159.9);      // Global

int main()
{
   cout << "\nThe first statement in main().\n" << endl;

   Article article2( 2222,"jogging shoes", 199.99);

   cout << "\nThe first call of test()." << endl;
   test(article1);                       // Passing by value

   cout << "\nThe second call of test()." << endl;
   test(article2);                       // Passing by value

   cout << "\nThe last statement in main().\n"
        << "\nThere are still " << Article::getCount()
        << " objects\n" << endl;

   return 0; 
}


void test( Article a)     // Calls the copy constructor
{
   cout << "\nThe given object:" << endl;
   a.print();

   static Article bike( 3333, "bicycle", 999.0);
   cout << "\nThe static object in function test():"
        << endl; 
   bike.print();

   cout << "\nThe last statement in function test()"
        << endl;
}

