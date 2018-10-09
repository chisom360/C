// calc_new.cpp: New version of function calc(),
//               that throws exceptions of type 
//               MathError.
// ----------------------------------------------------

#include <string>
#include <iostream>
using namespace std;

class MathError
{
   private:
     string message;
   public:
     MathError( const string& s) : message(s) {}
     const string& getMessage() const {return message;}
};

double calc( int a, int b ) throw(MathError);

int main()
{
   int x, y;
   bool flag = false;

   do
   {
     try                                 // try block
     {
       cout << "Enter two positive integers: ";
       cin >> x >> y;
       cout << x <<"/"<< y <<" = "<< calc( x, y) << endl;
       flag = true;                // To leave the loop.
     }
     catch( MathError& err)              // catch block
     {
       cerr << err.getMessage() << endl;
     }
   }while( !flag);
   // continued ...

   return 0; 
}

double calc( int a, int b ) throw (MathError)
{
   if( b < 0 )
      throw MathError("Denominator is negative!");
   if( b == 0 )
      throw MathError("Division by 0!");

   return ((double)a/b);
}
