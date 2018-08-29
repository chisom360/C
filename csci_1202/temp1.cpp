/*     FILE: temp1.cpp     */

// Templatized version of a safe_array.
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class safe_array{
    T * ptr;
    int size;
  public:
    safe_array(int length);
    safe_array(const safe_array & param);
    ~safe_array( ){ delete [ ] ptr;}
    int safe_size( )const{return size;}
    T &operator[ ](int index);
    const T &operator[ ](int index)const;
    safe_array &operator=(const safe_array & operand2);
   
    int getSize( ) const{ return size;}
};
 
template <class T>
safe_array<T>::safe_array(int length)
{
   ptr = new T[size=length];
}
 
template <class T>
safe_array<T>::safe_array(const safe_array & param)
{
   ptr = new T[size=param.size];
   for(int i=0; i<size; i++)
     ptr[i] = param.ptr[i];
}

template <class T>
safe_array<T> & safe_array<T>::operator=(const safe_array & operand2)
{
    if(this != &operand2){
      delete [ ] ptr;
      ptr = new T[size=operand2.size];
      for(int i=0; i<size; i++)
        ptr[i] = operand2.ptr[i];
    }
    return *this;
}
 
template <class T>
T & safe_array<T>::operator[ ](int index)
{
    if (index < 0 || size-1 < index)
      abort( );
    return ptr[index];
}
 
template <class T>
const T & safe_array<T>::operator[ ](int index)const
{
  if (index < 0 || size-1 < index)
    abort( );
  return ptr[index];
}
 
int main( )
{
   safe_array<int> ar(5);
   safe_array<int> ar2(7);
 
   for(int i=0; i<ar.getSize( ); i++)
      ar[i] = i;
 
   for(int i=0; i<ar2.getSize( ); i++)
      ar2[i] = i*10; 
 
   for(int i=0; i<ar.getSize( ); i++)   // display array ar
      cout << "ar[" << i << "] = " << ar[i] << endl;
 
   cout << endl;
   for(int i=0; i<ar2.getSize( ); i++)   // display array ar2
      cout << "ar2[" << i << "] = " << ar2[i] << endl;
 
   ar2 = ar;
 
   cout << endl;
   for(int i=0; i<ar2.getSize( ); i++)   // display array ar2
      cout << "ar2[" << i << "] = " << ar2[i] << endl;
 
   return 0;
}


/*    OUTPUT: temp1.cpp

	ar[0] = 0
	ar[1] = 1
	ar[2] = 2
	ar[3] = 3
	ar[4] = 4
	
	ar2[0] = 0
	ar2[1] = 10
	ar2[2] = 20
	ar2[3] = 30
	ar2[4] = 40
	ar2[5] = 50
	ar2[6] = 60
	
	ar2[0] = 0
	ar2[1] = 1
	ar2[2] = 2
	ar2[3] = 3
	ar2[4] = 4

*/
