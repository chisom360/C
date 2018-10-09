// telList_t.cpp 
// Manages a telephone list.
// --------------------------------------------------------
#include "telList.h"      // Definition of class TelList
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

inline void cls()
{
   cout << "\033[2J\n";   // Output only new-lines , if ANSI
}                         // control characters are not available.
 
inline void go_on()
{
   cout << "\n\nGo on with return! ";
   cin.sync();  cin.clear();           // No previous input
   while( cin.get() != '\n')
       ;
}

int menu();                            // Reads a command

char header[] =
"\n\n                *****  Telephone List  *****\n\n";

TelList myFriends;               // A telephone list

int main()
{
  int action = 0;                // Command
  string name;                   // Reads a name

  myFriends.append("Lucky, Peter", "0203-1234567");

  while( action != 'Q')
  {
    action = menu();
    cls();
    cout << header << endl;

    switch( action)
    {
      case 'D':                          // Show all
                 myFriends.print(); 
                 go_on();
                 break;

      case 'F':                          // Search
                 cout << 
                 "\n--- To search for a phone number ---\n"
                 "\nEnter the beginning of a name: ";
                 getline( cin, name);
                 if( !name.empty())
                 {
                   myFriends.print( name);
                   go_on();
                 }
                 break;

      case 'A':                          // Insert
                 myFriends.getNewEntries();
                 break;
 
      case 'E':                          // Delete
                 cout <<
                   "\n--- To delete a telephone entry. ---\n "
                   "\nEnter the complete name: ";
                 getline( cin, name);
                 if( !name.empty())
                 {
                   if( !myFriends.erase( name))
                      cout << name << " not found!"
                           << endl;
                   else
                      cout << "Entry for " << name
                           << " deleted!" << endl;
                   go_on();
                 }
                 break;

      case 'Q':  cls();                  // To terminate
                 break;
    }
  } // End of while

  return 0;
}

int menu()
{
   static char menuStr[] =
   "\n\n              D = Display all entries"
   "\n\n              F = Find a telephone number"
   "\n\n              A = Append a new entry "
   "\n\n              E = Erase an entry "
   "\n\n              Q = Quit the program"
   "\n\n Your choice:  ";

   cls();
   cout << header << menuStr;

   char choice;   
   cin.sync(); cin.clear();      // No previous input
   if( !cin.get(choice))
      choice = 'Q';
   else
      choice = toupper(choice);
   
   cin.sync();                   // Clear input buffer
   return choice;
}
