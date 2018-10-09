// ------------------------------------------------------
// bits_t.cpp
// Demonstrates bitwise operators. 
// ------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

void putbits( unsigned int n);  // Prototype of putbits() 

int main()                   // Learning bitwise operations
{
   int  x, y, count;
   char yn;

   do
   {
     cout << "\n\n   ******  BITWISE OPERATIONS  ******\n";

     cout << "\nPlease enter two integers.\n\n"
          << "1st number --> ";
     cin >> x;

     cout << "2nd number --> ";
     cin >> y;

     cout << "\nThe bit pattern of " 
          << setw(6) << x << " = x  :    ";
     putbits(x); 

     cout << "\nThe bit pattern of " 
          << setw(6) << y << " = y  :    ";
     putbits(y); 

     cout << "\nThe bit pattern of      x & y  :    "; 
     putbits(x&y);

     cout << "\nThe bit pattern of      x | y  :    ";
     putbits(x|y); 

     cout << "\nThe bit pattern of      x ^ y  :    ";
     putbits(x^y);

     cout << "\n\nHow many bit positions"
             " is x to be shifted?"
          << "\nNumber --> ";
     cin >> count;
 
     if( count < 0  ||  count > 15)
     {
        cout << "Invalid input!"
             << " Shifting by one bit position.\n";
        count = 1;
     }
     cout << "\nThe bit pattern of     x << " 
          << setw(2) << count << " :    ";
     putbits( x << count); 

     cout << "\nThe bit pattern of     x >> "
          << setw(2) << count << " :    ";
     putbits( x >> count); 

     cout << "\nTo repeat (y/n)? ";
     cin >> yn; 
     while( (yn | 0x20) != 'y'  &&  yn != 'n')
       ;

   }while( yn == 'y');

   return 0;
}

// ------------------------------------------------------
// Output the bit pattern of n (only the 16 lower bits).

void putbits( unsigned int n ) 
{                            
   int i;

   for( i = 15; i >= 0 ; --i)
   {
      cout << (char)( ((n>>i) & 1) + '0');   // i-th bit
      if( i % 4 == 0  &&  i > 0)     // and after 4 bits 
         cout << ' ';                // one blank. 
   }
}
