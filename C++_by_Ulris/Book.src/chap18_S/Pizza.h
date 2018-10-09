// ----------------------------------------------------
// Pizza.h 
// Header file for Pizza_W.cpp and Pizza_R.cpp.
// ----------------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Structure of a record:
struct Pizza {  char  name[32];  float price;  };

#define MAXCNT     20           // Maximum number of pizzas
#define FILENAME  "pizza.fle"

inline void header()
{
  cout << "      * * *  P I Z Z A  P R O N T O  * * *\n\n"
       << endl;
} 

