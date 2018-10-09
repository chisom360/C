// stackn_t.cpp: Testing the Stack template Stack<T, n>
// ----------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

#include "stackn.h"

typedef Stack<unsigned, 256> USTACK; 
                                 
void fill(  USTACK& stk );
void clear( USTACK& stk );

int main()
{
    USTACK ustk;            // Create and fill the 
    fill( ustk);            // original stack.
    
    USTACK ostk(ustk);      // Copy.

    cout << "\nThe copy: " << endl;
    clear( ostk);           // Output and clear the copy.
    
    cout << "\nThe original: " << endl;
    clear( ustk );          // Output and clear the original.
   
    return 0;
}

void fill( USTACK& stk ) 
{
    unsigned x;
    cout << "Enter positive integers (quit with 0): \n";
    
    while( cin >> x  && x != 0 )
      if( !stk.push(x) )
      { 
          cerr << "Stack is full!";
          break;
      }
}

void clear( USTACK& stk ) 
{
    if(stk.empty()) 
        cerr << "Stack is empty!" << endl;
    else
    {  
       unsigned x;
       
       while( stk.pop(x))
         cout << setw(8) << x << "  ";
       cout << endl;
    }
}
