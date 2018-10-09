// pizza_W.cpp 
// Demonstrating output of records block by block.
// ---------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

char header[] =
"    * * *  P I Z Z A  P R O N T O  * * *\n\n";

// Record structure:
struct Pizza { char name[32];  float price; };
const int MAXCNT = 10;

Pizza pizzaMenu[MAXCNT] = 
{
   { "Pepperoni", 9.90F },  { "White Pizza", 15.90F },
   { "Ham Pizza", 12.50F }, { "Calzone", 14.90F }
};

int cnt = 4;
char pizzaFile[256] = "pizza.fle";

int main()                       // To write records. 
{
   cout << header  << endl;

   // To write data into the file:
   int exitCode = 0;
   ofstream outFile( pizzaFile, ios::out|ios::binary );
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
           cerr << "Error writing!" << endl;
           exitCode = 2;
        }
   }

   if( exitCode == 0)
     cout << "\nData has been added to file " 
          << pizzaFile << "\n" << endl;

   return  exitCode;
}
