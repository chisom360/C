// ----------------------------------------------------
// circle.cpp
// Defines and calls the function circle().
// ----------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Prototype of circle():
void circle( const double& rad, double& um, double& fl);
 
const double startRadius =  0.5,     // Start, end and
             endRadius   = 10.0,     // step width of
             step        =  0.5;     // the table

string header = "\n      ***** Computing Circles ***** \n",
       line( 50, '-');

int main()
{
    double rad, circuit, area;

    cout << header << endl;
    cout << setw(10) << "Radius" 
         << setw(20) << "Circumference"
         << setw(20) << "Area\n" << line << endl;

    cout << fixed;           // Floating point presentation
    for( rad = startRadius;
         rad < endRadius + step/2;  rad += step)
    {
      circle( rad, circuit, area);
      cout << setprecision(1)<< setw(8)  << rad
           << setprecision(5)<< setw(22) << circuit
                             << setw(20) << area <<endl;
    }

    return 0;
}
 

// Function circle(): Compute circumference and area.
void circle( const double& r, double& c, double& a)
{
   const double pi = 3.1415926536;
   c = 2 * pi * r;
   a = pi * r * r;
}

