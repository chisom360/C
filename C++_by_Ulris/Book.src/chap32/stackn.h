// stackn.h: Class Template Stack<T, n>
// ---------------------------------------

template <class T, int n>
class Stack
{
  private:
    T   vek[n];      // Array
    int tip;         // Stack  tip
    int max;         // maximum number of elements

  public:
    Stack(){ max = n; tip = 0; };

    bool empty(){ return (tip == 0); }
    bool push( const T& x);
    bool pop(T& x);
};

template<class T, int n>
bool Stack<T, n>::push( const T& x)
{ 
   if(tip < max - 1)
   { 
      vek[tip++] = x;
      return true;
   }
   else return false;
}

template<class T, int n>
bool Stack<T, n>::pop(T& x )
{
   if(tip > 0) 
   {
      x = vek[--tip];
      return  true;
   }
   else 
      return false;
}
