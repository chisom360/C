/*     FILE: temp5.cpp     */

// Class stack is now being templatized.
#include <iostream>
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

  cout << "Pushing:\n";
  for(int i=0; i<5; i++){
     st.push(i);
     cout << i << endl;
  }

  cout << "\nPop-ing:\n";
  for(int i=0; i<5; i++)   // display stack contents
     cout << st.pop( ) << endl;

  stack<float> st2(5);

  cout << "\n\nPushing:\n";
  for(int i=0; i<5; i++){
     st2.push(i*0.3);
     cout << i*0.3 << endl;
  }

  cout << "\nPop-ing:\n";
  for(int i=0; i<5; i++)   // display stack contents
     cout << st2.pop( ) << endl;

   // cout << st.pop( ) << endl;   // underflow stack

  return 0;
}



/*    OUTPUT: temp5.cpp

	Pushing:
	0
	1
	2
	3
	4
	
	Pop-ing:
	4
	3
	2
	1
	0
	
	
	Pushing:
	0
	0.3
	0.6
	0.9
	1.2
	
	Pop-ing:
	1.2
	0.9
	0.6
	0.3
	0

*/
