// ----------------------------------------------------
// Pizza_r.cpp 
// Demonstrating block by block reading of records.
// ---------------------------------------------------

#include "Pizza.h"

char pizzaFile[256] = FILENAME;

int main()              // Read and display records. 
{
   header();

   ifstream inFile( pizzaFile, ios::in | ios::binary);
   if( !inFile)
   {
      cerr << "Pizza file does not exist!" << endl;
      return 1;
   }

   Pizza onePizza;
   int cnt = 0;

   cout << "\n-------------------------------------------"
        << "\nThe available pizzas:\n" << endl;

   cout << fixed << setprecision(2);
   while( true)
      if( !inFile.read( (char*)&onePizza, sizeof(Pizza)) )
          break;
      else
      {
          cout << setw(20) << onePizza.name
               << setw(10) << onePizza.price << endl;
          ++cnt;
      }

   cout << "\n------------------------------------------\n"
        << endl;

   if( !inFile.eof())
   {
      cerr << "Error reading file!" << endl;
      return 2;
   }
   else
      cerr << "These are " << cnt << " pizzas!\n" << endl;

   return 0;
}

