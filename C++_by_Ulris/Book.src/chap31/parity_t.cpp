// parity_t.cpp: Defines the function parity(), which
//               computes the parity of an unsigned
//               value. 
// Returns:      0, if the number of 1-bits is even,
//               1  otherwise.
// ---------------------------------------------------

#include <iostream>
using namespace std;

int parity( unsigned int n);

int main()
{
    unsigned int x;       

    cout << "Please enter a positive integer:  "; cin >> x;
    
    if(parity(x) != 0)
        cout << "The value " << x << " contains an uneven number of bits";
    else
        cout << "The value " << x << " contains an even number of bits";
    cout << endl;


    return 0;
}

inline unsigned int bit0( unsigned int x ) 
{ 
   return (x & 1); 
}

int parity( unsigned int n)
{
   unsigned int par = 0;

   for( ; n != 0; n >>=1 )
     par ^= bit0(n);

   return (par);
}
 
