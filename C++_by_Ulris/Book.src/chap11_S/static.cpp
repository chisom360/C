// static.cpp
// Tests an internal static variable
// --------------------------------------------------- 

#include <iostream>
#include <iomanip>
using namespace std;

double x = 0.5,
       fun(void);

int main()
{
   while( x < 10.0 )
   {
      x += fun();
      cout << "     Within main(): " 
           << setw(5) << x << endl;
   }
   return 0;
}

double fun()
{
   static double x = 0;

   cout << "      Within fun():" 
        << setw(5) << x++;
   return x;
}

