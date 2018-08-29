/*     FILE: except4.cpp     */

// Exceptions can be caught and then rethrown
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

class safe_array{
   int * ptr;
   int size;
public:
   safe_array(int length);
   safe_array(const safe_array & param);
   ~safe_array( ){ delete [ ] ptr;}
   int &operator[ ](int index);
   const int &operator[ ](int index)const;
   safe_array &operator=(const safe_array & operand2);
   
   int getSize( ) const{ return size;}
   
   class indexException{
    int index;
  public:
    indexException(int val){index = val;}
    int getIndex( ){return index;}
  };

};

safe_array::safe_array(int length)
{
   ptr = new int[size=length];
}

safe_array::safe_array(const safe_array & param)
{
   ptr = new int[size=param.size];
   for(int i=0; i<size; i++)
     ptr[i] = param.ptr[i];
}

safe_array & safe_array::operator=(const safe_array & operand2)
{
   if(this != &operand2){
     delete [ ] ptr;
     ptr = new int[size=operand2.size];
     for(int i=0; i<size; i++)
       ptr[i] = operand2.ptr[i];
   }
   return *this;
}

int & safe_array::operator[ ](int index)
{
   if (index < 0 || size-1 < index)
     throw indexException(index);
   return ptr[index];
}

const int & safe_array::operator[ ](int index)const
{
   if (index < 0 || size-1 < index)
     throw indexException(index);
   return ptr[index];
}

void func(safe_array& ar, int number) // This function produces the exception
{                                    // ... and catches it, then rethrows it.
  try{
   for(int i=0; i<number; i++)
    ar[i] = 22;
  }
  catch(safe_array::indexException x)
  {
    cout << "func( ) caught bad index: " << x.getIndex( ) << endl;
    throw;  // exception is re-"raised"
  }

}

int main( )
{
  safe_array ar(5);

  for(int i=0; i<5; i++)
     ar[i] = i;

  try{
    func(ar,7);
  }
  catch(safe_array::indexException x)
  {
    cout << "main caught bad index: " << x.getIndex( ) << endl;
    cout << "Could attempt to \"fix\" the error." << endl;
  }

  cout << "Leaving main( ), returning 0." << endl;
  return 0;
}



/*    OUTPUT: except4.cpp

	func() caught bad index: 5
	main caught bad index: 5
	Could attempt to "fix" the error.
	Leaving main(), returning 0.

*/
