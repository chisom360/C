// string1.cpp: Using strings

#include <iostream>
#include <string>
using namespace std;

string prompt("Enter a line of text: "),   // Global
       line( 50, '*');                     // strings

int main()
{
   string text;                  // Empty string

   cout << line << endl << prompt << endl;
   
   getline( cin, text);          // Reads a line of text
   
   cout << line << endl
        << "Your text is " << text.size() 
        << " characters long!" << endl;
                                 // Two new strings: 
   string copy(text),            // a copy and the 
          start(text,0,10);      // first 10 characters
                                 // starting with 
                                 // position 0. 
   
   cout << "Your text:\n" << copy << endl;
   
   text = "1234567890";          // Assignment
   
   cout << line << endl
        << "The first 10 characters:\n" << start << endl
        << text << endl;
   
   return 0;
}

