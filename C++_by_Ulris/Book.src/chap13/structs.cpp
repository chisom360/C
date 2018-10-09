// structs.cpp 
// Defines and uses a struct.
// ---------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Representative  // Defining struct Representative
{
  string name;         // Name of a representative.
  double sales;        // Sales per month.
};

inline void print( const Representative& v)
{
   cout << fixed << setprecision(2)
        << left  << setw(20) << v.name
        << right << setw(10) << v.sales << endl;
}

int main()
{
   Representative rita, john; 

   rita.name   = "Strom, Rita"; 
   rita.sales  = 37000.37;
   john.name   = "Quick, John";
   john.sales  = 23001.23;

   rita.sales += 1700.11;            // More Sales

   cout << "Representative         Sales\n" 
        << "------------------------------" << endl;
   print( rita);
   print( john);

   cout << "\nTotal of sales: "
        << rita.sales + john.sales << endl;
   
   Representative *ptr = &john;         // Pointer ptr. 
                                        // Who gets the 
   if( john.sales < rita.sales)         // most sales?
     ptr = &rita;

   cout << "\nSalesman of the month: "
        << ptr->name << endl;   // Representative's name
                                // pointed to by ptr. 
   return 0;
}
