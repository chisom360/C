//  numGame.cpp  :  A numerical game against the computer

#include <cstdlib>    // Prototypes of srand() and rand()
#include <ctime>      // Prototype of time() 
#include <iostream>
using namespace std;

int main()
{
   int  number, attempt; 
   char rf = 'r';            // To repeat or finish.
   long sec;
 
   time( &sec);              // Get the time in seconds.
   srand((unsigned)sec);     // Seeds the random number generator.  

   cout << "\n\n          "
        << " *******   A NUMERICAL GAME   *******" << endl;
 
   cout << "\n\nRules of the game:" << endl;
   while( rf == 'r')
   {
     cout << "I have a number between 1 and 15 in mind\n"
          << "You have three chances to guess correctly!\n"
          << endl;

     number = (rand() % 15) + 1;
 
     bool found = false;     int count = 0;
     
     while( !found  && count < 3 )
     {
        cin.sync();             // Clear input buffer
        cin.clear();
        cout << ++count << ". attempt:   ";
        cin >> attempt;
        if(attempt < number)      cout << "too small!"<< endl;
        else if(attempt > number) cout << "too big!"<< endl;
        else                      found = true;
     }

     if( !found)
       cout << "\nI won!"
            << " The number in question was: " << number << endl;
     else
       cout << "\nCongratulations! You won!" << endl;

     cout << "Repeat --> <r>    Finish --> <f>\n";
     do
       cin.get(rf);
     while( rf != 'r' &&  rf != 'f');
   }

   return 0;  
}
