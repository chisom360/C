// Passw1.cpp
// Functions getPassword() and timediff()
// to read and examine a password.
// -----------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

long timediff(void);                      // Prototype

static string secret = "ISUS";            // Password 
static long  maxcount = 3, maxtime = 60;  // Limits

bool getPassword()      // Reads and checks a password.
{              // Return value: true, if password is ok.
   bool ok_flag = false;         // For return value 
   string word;                  // For input 
   int count = 0, time = 0;

   timediff();                   // To start the stop watch
   while( ok_flag != true && 
          ++count <= maxcount)   // Number of attempts 
   {
      cout << "\n\nEnter the password:  ";
      cin.sync();                // Clear input buffer
      cin >> setw(20) >> word;
      time += timediff();
      if( time >= maxtime )      // Within time limit?
         break;                  // No!
      if( word != secret)
         cout << "Invalid Password!" << endl;
      else 
         ok_flag = true;         // Give permission
    }
    return ok_flag;              // Result
}

long timediff()              // Returns the number of 
{                            // seconds since the last call.
    static long  sec = 0;    // Time of last call.

    long  oldsec = sec;      // Saves previous time.
    time( &sec);             // Reads new time.
    return (sec - oldsec);   // Return the difference.
}


int main()
{
    if( getPassword())
        cout << "Welcome!" << endl;
    else
        cout << "No authorization!" << endl;

    return 0;
}
