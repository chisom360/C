// exerc1.cpp
// Outputs a table of exchange:  Euro and US-$

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   long   euro, maxEuro;       // Amount of Euros 
   double rate;                // Exchange rate Euro <-> $

   cout << "\n* * * TABLE OF EXCHANGE "
        << " Euro - US-$ * * *\n\n";

   cout << "\nPlease give the rate of exchange: "
            " one Euro in US-$: ";
   cin >> rate;
   cout << "\nPlease enter the maximum euro: ";
   cin >> maxEuro;

   //  ---  Outputs the table  ---
                                 // Titles of columns:
   cout << '\n'
        << setw(12) << "Euro" << setw(20) << "US-$"
        << "\t\tRate: " << rate << endl;

                                 // Formatting US-$:
   cout << fixed << setprecision(2) << endl;

   long lower, upper,         // Lower and upper limit
        step;                 // Step width 

                    // The outer loop determines the used
                    // lower limit and the step width:
   lower=1, step=1;
   while( lower <= maxEuro)
   {
                    // The inner loop outputs a "block":
     euro = lower;
     upper = step*10;
     while( euro <= upper && euro <= maxEuro)
     {
       cout << setw(12) << euro
            << setw(20) << euro*rate << endl;
       euro += step;
     }
     step *= 10, lower = 2*step;
   }

   return 0;
}
