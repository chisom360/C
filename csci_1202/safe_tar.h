/*     FILE: safe_tar.h     */

#ifndef _safe_tar_h
#define _safe_tar_h
 
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

#endif
