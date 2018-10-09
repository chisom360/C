// getbin_t.cpp: Defines the function getbin(), which
//               reads a binary number (ex. 0101... )
//               from the standard input and returns the
//               value of type unsigned int.
// --------------------------------------------------

#include <iostream>
using namespace std;

unsigned int getbin();

int main()
{
   unsigned int result;

   cout << "Please enter a binary number (ex. 1011):" << endl;

   result =  getbin();

   cout << "Its decimal value is: " << result << endl;

   return 0;
}

unsigned int getbin()
{
   char c;
   unsigned int val = 0;
 
   while ( (c = cin.get()) == ' ' || c == '\t' )
      ;            // To ignore leading blanks and tabs 
 
   while( c == '0' || c == '1' )    // Read and convert 
   {                                // the binary number
      val = (val << 1) | (c - '0');
      c = cin.get();
   }

   return val;
}
