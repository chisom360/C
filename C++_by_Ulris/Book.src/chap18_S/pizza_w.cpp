// ----------------------------------------------------
// Pizza_w.cpp 
// Demonstrating blockwise writing of records.
// ----------------------------------------------------

#include "Pizza.h"

Pizza pizzaMenu[MAXCNT] = 
{
   { "Pepperoni", 9.90F },  { "White Pizza", 15.90F },
   { "Ham Pizza", 12.50F }, { "Calzone", 14.90F }
};

int  cnt = 4;
char pizzaFile[256] = FILENAME;

int main()                         // Write records. 
{
   int i;

   header();
   cout << "\nOur standard offer:\n" << endl; 

   cout << fixed << setprecision(2);
   for( i = 0; i < cnt; ++i)
      cout << setw(20) << pizzaMenu[i].name
           << setw(10) << pizzaMenu[i].price << endl;
   cout << "\n-----------------------------------------\n"
        << endl;
 
   // Input more pizzas via keyboard:
   while( cnt < MAXCNT)
   {
     cin.sync(); cin.clear();
     cout << "What pizza should be added "
          << "to the menu?\n\n" << "Name:  ";  
     cin.getline( pizzaMenu[cnt].name, 32);
     if( pizzaMenu[cnt].name[0] == '\0')
       break;

     cout << "Price: ";
     cin >> pizzaMenu[cnt].price;

     if( !cin)
       cerr << "Invalid input!" << endl; 
     else
       ++cnt;
     
     if( cnt < MAXCNT)
       cout << "\n... and the next pizza!\n"
            << "Stop with <Return>.\n";
   }

   // Add data to the file:
   int exitCode = 0;
   ofstream outFile( pizzaFile, ios::out | ios::binary);
   if( !outFile)
   {
      cerr << "Error opening the file!" << endl;
      exitCode = 1;
   }
   else
   {    
      for( int i = 0; i < cnt; ++i)
        if( !outFile.write( (char*)&pizzaMenu[i], sizeof(Pizza)) )
        {
           cerr << "Error writing to file!"
                << endl;
           exitCode = 2;
        }
   }

   if( exitCode == 0)
     cout << "\nData added to file " << pizzaFile
          << ".\n" << endl;

   return exitCode;
}
