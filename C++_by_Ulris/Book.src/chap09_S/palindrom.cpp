// -----------------------------------------------------
// palindrom.cpp: Reads and compares lines of text. 
// -----------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

string header = " * * * Testing palindromes * * * ",
       prompt = "Enter a word: ",
       line( 50, '-');

int main()
{
   string word;                        // Empty string
   char key = 'y';

   cout << "\n\t" << header << endl;
   while( key == 'y' || key == 'Y') 
   {
      cout << '\n' << line  << '\n'
           << prompt;

      cin >> word;

      // Compares the first and last character,
      // the second and the second to last etc.
      int i = 0,
          j = word.length() - 1;
      for( ; i <= j ; ++i, --j)   
        if( word[i] != word[j] ) 
            break;

      if( i > j)                   // All characters equal?
         cout << "\nThe word " << word 
              << " is a P A L I N D R O M E !" << endl;
      else
         cout << "\nThe word " << word
              << " is not a palindrome" << endl;

      cout << "\nRepeat? (y/n) ";
      do
        cin.get(key);
      while(    key != 'y' && key != 'Y'
             && key != 'n' && key != 'N');
      cin.sync();
   }

   return 0;
}
