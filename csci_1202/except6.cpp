/*     FILE: except6.cpp     */

// A class of exception is defined and will be thrown when class
// ... safe_array detects an "unsafe" array index value.

// If an exception is caught it is considered "handled."

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
  safe_array &operator=(const safe_array & operand2);
  class index_exception{
    int index;
  public:
    index_exception(int val){index = val;}
    int get_index( ){return index;}
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
     throw index_exception(index);
   return ptr[index];
}

int main( )
{
  safe_array ar(5);
  int limit = 7;

  for(int i=0; i<5; i++)
     ar[i] = i;

  for(int i=0; i<5; i++)   // display array ar
     cout << "ar[" << i << "] = " << ar[i] << endl;

  cout << "\nForce an exception: " << endl;

  for(int i=limit; i>=0; i--)   // overdisplay array ar in the
  {                             // ... negative direction
    try{
        cout << "ar[" << i << "] = " << ar[i] << endl;
    }
    catch(safe_array::index_exception x)
    {
     cout << "Caught bad index: " << x.get_index( ) << endl;
    }
  }

  return 0;
}



/*    OUTPUT: except6.cpp

	ar[0] = 0
	ar[1] = 1
	ar[2] = 2
	ar[3] = 3
	ar[4] = 4
	
	Force an exception: 
	Caught bad index: 7
	Caught bad index: 6
	Caught bad index: 5
	ar[4] = 4
	ar[3] = 3
	ar[2] = 2
	ar[1] = 1
	ar[0] = 0

*/
