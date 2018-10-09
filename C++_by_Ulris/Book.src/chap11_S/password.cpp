// -----------------------------------------------------
// Password.cpp
// Testing the functions getPassword() and
// changePassword().
//
// After entering the password correctly (max. three
// attemps within 60 seconds), the user can change it.
// -----------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

bool getPassword(void);            // Read a password.
bool changePassword(void);         // Change a password.

// Inline functions:
inline void cls()  { cout << "\033[2J"; }

inline void go_on()
{
   cout << "\n\nGo on with return! ";
   cin.sync();  cin.clear();       // Only new input
   while( cin.get() != '\n')
       ;
}

inline char getYesOrNo()      // Read character Y or N.
{
   char c = 0;
   cin.sync();  cin.clear();  // Just new input
   do
   {
     cin.get(c);
     c = toupper(c);  // Permitting lower case letters also.
   }
   while( c != 'Y'  && c != 'N');
   cin.sync();
   return c; 
}


static string header =
"\n\n      ****  Test password handling  ****\n\n";

static string menu =
"\n\n              B = Booking "
"\n\n              E = End of program"
"\n\nYour choice:  ";

int main()
{
   char choice = 0;

   while( choice != 'E')
   {
     cls();
     cout << header << menu;           // Header and Menu

     cin.get(choice);  
     choice = toupper(choice);

     cls();
     cout << header << endl;           // Header

     switch( choice)
     {
       case 'B':                       // Booking
         if( !getPassword() )
         {
            cout << "Access denied!" << endl;
            go_on();
         }
         else
         { cout << "Welcome!\n\n"
            << "Do you want to change the password? (y/n)";
    
            if( getYesOrNo() == 'Y')
            {
              if( changePassword() )
                cout << "Password changed!" << endl;
              else 
                cout << "Password unchanged!" << endl;

              go_on();
            }
            // Place statements for booking here.

         }
         break;

       case 'E':
//         cls();
         cout << "\n    Bye Bye!" << endl;
         break;
     }
   } // End of while

   return 0;
}
