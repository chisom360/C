// reverse.cpp 
// Defines and calls the function reverse().
// reverse() copies a C string into another C string
// and reverses the order of characters. 
// -----------------------------------------------------

#include <iostream>
using namespace std;
#include <string.h>      // Header-File for C strings,
                         // here for strlen().
void reverse( char str[], char umstr[]);  // Prototype

int main()               // Read a word and 
{                        // output in reversed order.
   const int CNT = 81;
   char word[CNT], revword[CNT];

   cout << "Enter a word: ";
   cin.width(CNT);       // maximum CNT-1 charcters
   cin >> word;

   reverse( word, revword);                // Call

   cout << "\nThe \"reversed\" word:   " << revword
        << endl ;

   return 0;
}

void reverse( char s1[], char s2[])      // Copies the
{                         // reversed C String s1 to s2
   int j = 0;

   for( int i = strlen(s1)-1; i >= 0; i--, j++)
      s2[j] = s1[i];

   s2[j] = '\0';                // Terminating character
}
