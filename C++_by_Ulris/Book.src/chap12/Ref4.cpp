// Ref4.cpp 
// Expressions with reference type exemplified by 
// assignments of strings.
// --------------------------------------------------

#include <iostream>
#include <string>
#include <cctype>                // For toupper()
using namespace std;

void strToUpper( string& );      // Prototype

int main()
{
   string text("Test with assignments\n");

   strToUpper(text);
   cout << text << endl;

   strToUpper( text = "Flowers");
   cout << text << endl;

   strToUpper( text += " cheer you up!\n");
   cout << text << endl;

   return 0;
}

void strToUpper( string& str)  // Converts the content 
{                              // of str to uppercase.
    int len = str.length();
    for( int i=0; i < len; ++i)
      str[i] = toupper( str[i]);
}
