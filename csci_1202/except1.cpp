/*     FILE: except1.cpp     */

// A class of exception is defined and will be thrown when class
// ... safe_array detects an "unsafe" array index value.
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;


class indexException{
  int index;
public:
  indexException(int val){index = val;}
  int getIndex( ){return index;}
};

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

int main( )
{
  safe_array ar(5);

  for(int i=0; i<5; i++)
     ar[i] = i;

  for(int i=0; i<5; i++)   // display array ar
     cout << "ar[" << i << "] = " << ar[i] << endl;

  cout << "\nTest exceptions: " << endl;

  try{
    for(int i=0; i<7; i++)   // overdisplay array ar
      cout << "ar[" << i << "] = " << ar[i] << endl;
  }
  catch(indexException x)
  {
    cout << "Caught bad index: " << x.getIndex( ) << endl;
    cout << "Could attempt to \"fix\" the error." << endl;
  }

  cout << "Leaving main( ), returning 0." << endl;
  return 0;
}



/*    OUTPUT: except1.cpp

	ar[0] = 0
	ar[1] = 1
	ar[2] = 2
	ar[3] = 3
	ar[4] = 4
	
	Test exceptions: 
	ar[0] = 0
	ar[1] = 1
	ar[2] = 2
	ar[3] = 3
	ar[4] = 4
	Caught bad index: 5
	Could attempt to "fix" the error.
	Leaving main(), returning 0.

*/
