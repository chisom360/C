// ----------------------------------------------------
// quadEqu.cpp
// Defines and calls the function quadEquation(),
// which computes the solutions of quadratic equations 
//            a*x*x + b*x + c = 0
// The equation and its solutions are printed by
// the function printQuadEquation().
// ----------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>              // For the square root sqrt()
using namespace std;

string header =
       " *** Solutions of Quadratic Equations ***\n",
       line( 50, '-');

// -----  Prototypes -----
// Computing solutions:
bool quadEquation( double a, double b, double c,
                    double* x1Ptr, double* x2Ptr);

// Printing the equation and its solutions:
void printQuadEquation( double a, double b, double c);

int main()   
{
   cout << header << endl;

   printQuadEquation( 2.0, -2.0, -1.5); 
   printQuadEquation( 1.0, -6.0, 9.0); 
   printQuadEquation( 2.0,  0.0, 2.0); 

   return 0;
}


// Prints the equation and its solutions:
void printQuadEquation( double a, double b, double c)
{
   double x1 = 0.0, x2 = 0.0;           // For solutions

   cout << line << '\n'
        << "\nThe quadratic equation:\n\t "
        << a << "*x*x + " << b << "*x + " <<  c << " = 0"
        << endl;
   
   if( quadEquation( a, b, c, &x1, &x2) )
   {
     cout << "has real solutions:"
          << "\n\t x1 = " << x1
          << "\n\t x2 = " << x2 << endl;
   }
   else
     cout << "has no real solutions!" << endl;
   
   cout << "\nGo on with return. \n\n";
   cin.get();
}

bool quadEquation( double a, double b, double c,
                   double* x1Ptr, double* x2Ptr)
// Computes the solutions of the quadratic equation:
//            a*x*x + b*x + c = 0
// Stores the solutions in the variables to which
// x1Ptr and x2Ptr point.
// Returns: true, if a solution exists,
//                otherwise false.
{
    bool return_flag = false;

    double help = b*b - 4*a*c;

    if( help >= 0)            // There are real solutions.
    {
      help = sqrt( help);

      *x1Ptr = (-b + help) / (2*a);
      *x2Ptr = (-b - help) / (2*a);

      return_flag = true;
    }
    return return_flag;
}
