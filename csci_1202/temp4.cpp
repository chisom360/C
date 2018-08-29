/*     FILE: temp4.cpp     */

// Class stack is now being templatized.
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

#include "safe_tar.h"

template <class T>
class stack{
   safe_array<T> ptr;
   int top;
public:
   stack(int size);
   stack(const stack & param);
   T pop( );
   void push(T value);
   stack<T> &operator=(const stack & operand2);
};

template <class T>
stack<T>::stack(int size):ptr(size)
{
   top = -1;
}

template <class T>
void stack<T>::push(T value)
{
   ptr[++top] = value;
}

template <class T>
T stack<T>::pop( )
{
   return ptr[top--];
}

template <class T>
stack<T>::stack(const stack & param):ptr(param.ptr)
{
   top = param.top;
}

template <class T>
stack<T> & stack<T>::operator=(const stack & operand2)
{
   if(this != &operand2){
     ptr = operand2.ptr;
     top = operand2.top;
   }
   return *this;
}

int main( )
{
  stack<int> st(5);
  
  cout << "int stack: " << endl;

  for(int i=0; i<5; i++){
     st.push(i);
     cout << "Pushed: " << i << endl;
  }

  for(int i=0; i<5; i++)   // display stack contents
     cout << "Popped: " << st.pop( ) << endl;

  stack<float> st2(5);
  
  cout << "\n\nfloat stack: " << endl;

  for(int i=0; i<5; i++){
     st2.push(i*0.3);
     cout << "Pushed: " << i*0.3 << endl;
  }

  for(int i=0; i<5; i++)   // display stack contents
     cout << "Popped: " << st2.pop( ) << endl;

   // cout << st.pop( ) << endl;   // underflow stack

  return 0;
}


/*    OUTPUT: temp4.cpp

	int stack: 
	Pushed: 0
	Pushed: 1
	Pushed: 2
	Pushed: 3
	Pushed: 4
	Popped: 4
	Popped: 3
	Popped: 2
	Popped: 1
	Popped: 0
	
	
	float stack: 
	Pushed: 0
	Pushed: 0.3
	Pushed: 0.6
	Pushed: 0.9
	Pushed: 1.2
	Popped: 1.2
	Popped: 0.9
	Popped: 0.6
	Popped: 0.3
	Popped: 0

*/
