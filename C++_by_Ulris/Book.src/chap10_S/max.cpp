// ----------------------------------------------------- 
// max.cpp 
// Defines and calls the overloaded functions Max().
// ------------------------------------------------------

// As long as just one function Max() is defined, it can 
// be called with all arguments that can be converted to 
// double, i.e. with values of type char, int or long.
// After overloading no clear conversion will be possible.

#include <iostream>
#include <string>
using namespace std;

inline double Max(double x, double y)
{
   return (x < y ? y : x);
}

inline char Max(char x, char y)
{
   return (x < y ? y : x);
}

string header("To use the overloaded function Max().\n"),
       line(50,'-');

int main()     // Several different calls to function Max() 
{
   double x1 = 0.0, x2 = 0.0;
    
   line += '\n';
   cout << line << header << line << endl;
   
   cout << "Enter two floating point numbers:"
        << endl;
   if( cin >> x1  &&  cin >> x2)
   {
       cout << "The greater number is " << Max(x1,x2)
            << endl;
   }
   else
       cout << "Invalid input!" << endl;

   cin.sync(); cin.clear();   // If an invalid input 
                              // was entered.
 
   cout << line
        << "And once more with characters!"
        << endl;
   
   cout << "Enter two characters:" 
        << endl;

   char c1, c2;
   if( cin >> c1  &&  cin >> c2)
   {
       cout << "The greater character is " << Max(c1,c2)
            << endl;
   }
   else
       cout << "Invalid input!" << endl;


   cout << "Testing with int arguments." << endl;
   int  a = 30, b = 50;
//   cout << Max(a,b) << endl;     // Error! Which 
                                 // function Max()?
   return 0;
}

