// ------------------------------------------------------
// article.cpp 
// Defines those methods of Article, which are
// not defined inline.
// Screen output for constructor and destructor calls.
// ------------------------------------------------------

#include "article.h"         // Definition of the class
#include <iostream>
#include <iomanip>
using namespace std;

// Global counter for the objects:
int count = 0;

// ------------------------------------------------------
// Define constructor and destructor:
Article::Article( long nr, const string& name, double sp)
{
   setNr(nr);   setName(name);   setSP(sp);
   ++count;
   cout << "Created object for the article " << name
        << ".\n"
        << "This is the " << count << ". article!" << endl;
}

Article::~Article()
{
   cout << "Cleaned up object for the article " << name
        << ".\n"
        << "There are still " << --count << " articles!"
        << endl;
}

// ------------------------------------------------------
// The method print() outputs an article.
void Article::print()
{
   long savedFlags = cout.flags();      // To mark the 
                                        // flags of cout. 
   cout << fixed << setprecision(2) 
        << "-----------------------------------------\n"
        << "Article data:\n"
        << "  Number ....:  " << nr    << '\n'
        << "  Name   ....:  " << name  << '\n'
        << "  Sales price:  " << sp    << '\n'
        << "-----------------------------------------"
        << endl;

   cout.flags(savedFlags);               // To restore 
                                         // old flags.
   cout << "  --- Go on with return --- ";
   cin.get();
}

