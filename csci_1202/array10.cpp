/*     FILE: array10.cpp     */

/* 
    A stack of integers.
    
    Capitalizing on the work done with the "safe" array
    type safe_ar.
*/ 
#include <iostream>
#include <cstdlib>

#include "safe_ar.h"
using namespace std;

class stack{
   safe_array ptr;
   int top;
public:
   stack(int size);
   stack(const stack & param);
   int pop( );
   void push(int value);
   stack &operator=(const stack & operand2);
};

stack::stack(int size):ptr(size)
{
   top = -1;
}

void stack::push(int value)
{
   ptr[++top] = value;
}

int stack::pop( )
{
   return ptr[top--];
}

stack::stack(const stack & param):ptr(param.ptr)
{
   top = param.top;
}

stack & stack::operator=(const stack & operand2)
{
   if(this != &operand2){
     ptr = operand2.ptr;
     top = operand2.top;
   }
   return *this;
}

int main( )
{
  int i;
  stack st(5);

  for(i=0; i<5; i++)
     st.push(i);

  for(i=0; i<5; i++)   // display stack contents
     cout << st.pop( ) << endl;

   // cout << st.pop( ) << endl;

  return 0;
}

/*    OUTPUT: array10.cpp

	4
	3
	2
	1
	0

*/
