// stack_t.cpp: Testing a stack
// ----------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

#include "stack.h"

typedef Stack<unsigned> USTACK;  // Stack for elements  
                                 // of type unsigned.
void fill(  USTACK& stk );
void clear( USTACK& stk );

int main()
{
    USTACK ustk(256);      // Create and fill 
    fill( ustk);           // the original stack,

    USTACK ostk(ustk);     // Copy.

    clear( ostk);          // Output and clear the copy.
    clear( ustk );         // Output and clear the original.

    return 0;
}

void fill( USTACK& stk ) 
{
    unsigned x;
    cout << "Enter positive integers (quit with 0): \n";
    while( cin >> x  && x != 0 )
      if( !stk.push(x) )
      { 
          cerr << "Stack is full!"; break;
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
