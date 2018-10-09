// -------------------------------------------------------
// TelList_.cpp 
// Organize a telephone list with class TelList.
// -------------------------------------------------------
//  To activate the cntrol characters, a corresponding
//  sreen driver has to be loaded.
//  Under Windows 9x this is done by the following line
//  in file CONFIG.SYS:
//         DEVICE = C:\Windows\Command\Ansi.sys
// -------------------------------------------------------

#include "telList.h"      // Definition of class TelList
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

inline void cls()
{
   cout << "\033[2J\n"; // If ANSI control characters are 
}                       // not available, output new-lines.
 
inline void go_on()
{
   cout << "\n\nGo on with return! ";
   cin.sync();  cin.clear();        // No previous input
   while( cin.get() != '\n')
       ;
}

int menu();               // Enter a command
char askForSave();        // Prompt user to save.

char header[] =
"\n\n          * * * * *  Telephone List  * * * * *\n\n";

TelList myFriends;       // A telephone list

int main()
{
  int action = 0;        // Command
  string name;           // Read a name

  while( action != 'Q')
  {
    action = menu();
    cls();  cout << header << endl;

    switch( action)
    {
      case 'D':                          // Show all
         myFriends.print(); 
         go_on();
         break;

      case 'F':                          // Search
         cout << "\n--- To search for a phone number ---\n"
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
         cout << "\n--- To delete a telephone entry. ---\n "
                 "\nEnter the complete name: ";
         getline( cin, name);
         if( !name.empty())
         {
             if( !myFriends.erase( name))
                  cout << name << " not found!" << endl;
             else
                  cout << "Entry for " << name << " deleted!" << endl;

             go_on();
         }
         break;

      case 'O':                          // To open a file
         if(myFriends.isDirty() && askForSave() == 'y')
            myFriends.save();
         if( myFriends.load())
            cout << "Telephone list read from file "
                 << myFriends.getFilename() <<"!"
                 << endl;
         else
            cerr << "Telephone list not read!"
                 << endl;
         go_on();
         break;

      case 'V':                          // Save as ...
         if( myFriends.saveAs())
           cout << "Telephone list has been saved in file: "
                << myFriends.getFilename() << " !" <<endl;
         else
            cerr << "Telephone list not saved!" << endl;
         go_on();
         break;

      case 'S':                          // Save
         if( myFriends.save())
            cout << "Telephone list has been saved in " 
                 << "the file " 
                 << myFriends.getFilename() << endl;
         else
            cerr << "Telephone list not saved!"
                 << endl;
         go_on();
         break;

     case 'Q':                           // Quit
         if( myFriends.isDirty()  &&  askForSave() == 'Y')
            myFriends.save();
         cls();
         break;
    }
  } // End of while

  return 0;
}

int menu()
{
   static char menuStr[] =
   "\n              D = Display all entries"
   "\n              F = Find a telephone number"
   "\n              A = Append a new entry "
   "\n              E = Erase an entry "
   "\n              -------------------------------------"
   "\n              O = Open a file"
   "\n              S = Save "
   "\n              V = Save as ..."
   "\n              -------------------------------------"
   "\n              Q = Quit the program"
 "\n\n Your choice: ";

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

char askForSave()
{
   char c;
   cout <<  "Do you want to save the phone list(y/n)? ";
   do
   {   cin.get(c);
       c = toupper(c);
   }while( c != 'Y'  &&  c != 'N');

   return c;
}
