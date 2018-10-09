// -------------------------------------------------------
// account_rw.cpp 
// Writes an array with objects of class Account to 
// a file and feed the array into another array.
// -------------------------------------------------------

#include "account.h"     // Definition of the class Account
#include <iostream>
#include <fstream>
using namespace std;

Account AccTab1[3] =
{
  Account("Lucky, Luke", 707070, -1200.99),
  Account("Mickey, Mouse", 123000, 2500.0),
  Account("Snoopy, Dog\n"          // String can contain more 
          "Cell #: 01771234567", 543001)    // than one line.
};

Account AccTab2[3];       // Calls to default constructor

int cnt = 3;

char file[] = "account.fle";

int main()
{
   int i = 0;

   // --- Write accounts to file --- 

   ofstream outFile( file, ios::out | ios::binary );
   if( ! outFile)
   {
     cerr << "Error opening file " << file
          << endl;
     return 1;
   }

   for( i = 0; i < cnt; ++i)
     if( !AccTab1[i].write(outFile) )
     {
       cerr << "Error writing to file " << file
            << endl;
       return 2;
     }

   outFile.close();
 
   // --- Reads accounts from file --- 

   ifstream inFile( file, ios::out | ios::binary );
   if( ! inFile)
   {
     cerr << "Error opening file " << file
          << endl;
     return 3;
   }

   for( i = 0; i < cnt; ++i)
     if( !AccTab2[i].read(inFile) )
     {
       cerr << "Error reading file " << file
            << endl;
       return 4;
     }

   inFile.close();
   
   // --- Displays the accounts read ---

   cout << "The file " << file << " contains the "
        << "following accounts:" << endl;

   for( i = 0; i < cnt; ++i)
      AccTab2[i].display();

   cout << endl;

   return 0;
}
