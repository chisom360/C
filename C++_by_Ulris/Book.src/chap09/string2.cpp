// string2.cpp: Reads several lines of text and
//              outputs in reverse order.

#include <iostream>
#include <string>
using namespace std;

string prompt("Please enter some text!\n"),
       line( 50, '-');

int main()
{
   prompt += "Terminate the input by an empty line.\n";

   cout << line << '\n' << prompt << line << endl;
   
   string text, line;          // Empty strings
   
   while( true) 
   {
      getline( cin, line);     // To read a line of text 
   
      if( line.length() == 0)  // Empty line?
        break;                 // Yes ->end of the loop

      text = line + '\n' + text;    // To insert a new 
                                    // line at the beginning.
   }
                                    // Output: 
   cout << line << '\n'
        << "Your lines of text in reverse order:"
        << '\n' << line << endl;
   cout << text << endl;
   
   return 0;
}


