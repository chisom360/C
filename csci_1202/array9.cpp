/*     FILE: array9.cpp     */

/* 
    A stack of integers.
*/ 
#include <iostream.h>
#include <stdlib.h>
using namespace std;

class stack{
   int * ptr;
   int size;
   int top;
public:
   stack(int size);
   stack(const stack & param);
   ~stack( ){ delete [ ] ptr;}
   int pop( );
   void push(int value);
   stack &operator=(const stack & operand2);
};

stack::stack(int size)
{
   ptr = new int[this->size=size];
   top = -1;
}

void stack::push(int value)
{
   if (top >= size)
     abort( );
   ptr[++top] = value;
}

int stack::pop( )
{
   if (top < 0)
     abort( );
   return ptr[top--];
}

stack::stack(const stack & param)
{
   ptr = new int[size=param.size];
   top = param.top;
   for(int i=0; i<=top; i++)
     ptr[i] = param.ptr[i];
}

stack & stack::operator=(const stack & operand2)
{
   if(this != &operand2){
     delete [ ] ptr;
     ptr = new int[size=operand2.size];
     top = operand2.top;
     for(int i=0; i<=top; i++)
       ptr[i] = operand2.ptr[i];
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

  cout << st.pop( ) << endl;  // pop one too many

  return 0;
}


/*    OUTPUT: array9.cpp

	4
	3
	2
	1
	0
	
	abnormal program termination

*/
