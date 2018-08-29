/*     FILE: stack_t.h     */

// Templatized class stack in a .h file.
#ifndef _stack_t_h
#define _stack_t_h
 
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

#endif
