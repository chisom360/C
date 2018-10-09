// stack.h : The class template Stack with 
//           methods push() and pop().
//----------------------------------------------------- 
template<class T>
class Stack
{
  private:
    T* basePtr;      // Pointer to array
    int tip;         // Stack tip
    int max;         // maximum number of elements

  public:
    Stack(int n){ basePtr = new T[n]; max = n; tip = 0;}
    Stack( const Stack<T>&);     
    ~Stack(){ delete[] basePtr; }

    Stack<T>& operator=( const Stack<T>& );

    bool empty(){ return (tip == 0); }
    bool push( const T& x);
    bool pop(T& x);
};

template<class T>
bool Stack<T>::push( const T& x)
{ 
   if(tip < max - 1)        // If there is enough space
   { 
      basePtr[tip++] = x;
      return true;
   }
   else
      return false;
}

template<class T>
bool Stack<T>::pop( T& x)
{
   if(tip > 0)              // If the stack is not empty
   {
      x = basePtr[--tip];
      return true;
   }
   else
      return false;
} 

template<class T>
Stack<T>::Stack( const Stack<T>& stk)
{
   tip = stk.tip;
   max = stk.max;

   basePtr = new T[max];

   for(int i = 0; i < tip; i++)
       basePtr[i] = stk.basePtr[i];
}

template<class T>
Stack<T>&  Stack<T>::operator=( const Stack<T>& )
{
   tip = stk.tip;
   max = stk.max;

   delete[] basePtr;
   basePtr = new T[max];

   for(int i = 0; i < tip; i++)
       basePtr[i++] = stk.basePtr[i];
}
