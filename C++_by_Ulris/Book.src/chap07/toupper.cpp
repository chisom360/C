//  toupper.cpp: A filter that converts to capitals.
//
//  Note:
//  The program reads characters from a file until end-of-file.
//  When reading keyboard input end-of-file is simulated by
//  ^Z (DOS) or ^D (Unix).
//  ---------------------------------------------------

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
   char c; 
   long nChar = 0,          // Counts all characters 
        nConv = 0;          // and converted characters.

   while ( cin.get(c) )     // As long as a character 
   {                        // can be read,
      ++nChar;              // to increment.
      if( islower(c))       // Lower case letter?
      {
         c = toupper(c);    // Converts the character
         ++nConv;           // and counts it.
      }
      cout.put(c);          // Outputs the character.
   }

   clog << "\nTotal of characters:           " << nChar
        << "\nTotal of converted characters: " << nConv
        << endl;

   return 0;
}

