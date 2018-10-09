// ---------------------------------------------------
// Article.cpp 
// Methods of Article, which are not defined  inline.
// Constructor and destructor output when called.
// ---------------------------------------------------

#include "Article.h"            // Definition of the class

#include <iostream>
#include <iomanip>
using namespace std;

// Defining the static data element:
int Article::countObj = 0;         // Number of objects

// Defining the constructor and destructor:

Article::Article( long nr, const string& name, double sp)
{
   setNr(nr);   setName(name);   setSP(sp);
   ++countObj;
   cout << "An article \"" << name
        << "\" is created.\n"
        << "This is the " << countObj << ". article!"
        << endl;
}
// Defining the copy constructor:
Article::Article( const Article& art)
:nr(art.nr), name(art.name), sp(art.sp)
{
   ++countObj;
   cout << "A copy of the article \"" << name
        << "\" is generated.\n"
        << "This is the " << countObj << ". article!"
        << endl;
}

Article::~Article()
{
   cout << "The article \"" << name
        << "\" is destroyed.\n"
        << "There are still " << --countObj << " articles!"
        << endl;
}

// The method print() outputs an article.
void Article::print()
{
   long savedFlags = cout.flags();    // To save flags of cout 
   cout << fixed << setprecision(2) 
        << "-----------------------------------------\n"
        << "Article Datas:\n"
        << "  Number ......:  " << nr    << '\n'
        << "  Name   ......:  " << name  << '\n'
        << "  Sales Price  :  " << sp    << '\n'
        << "-----------------------------------------" << endl;
   cout.flags(savedFlags);            // To restore old flags

   cout << "  --- Go on with return --- ";
   cin.get();
}


