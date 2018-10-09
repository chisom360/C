// FloatVek.cpp: 
// Implementing the methods of FloatArr.
// -----------------------------------------------------

#include "floatArr.h"
#include <iostream>
using namespace std;

FloatArr::FloatArr( int n )
{
   max = n;   cnt = 0;  
   arrPtr = new float[max];
}

FloatArr::FloatArr(int n, float val)
{
   max = cnt = n;
   arrPtr  = new float[max];

   for( int i=0; i < cnt; ++i)
       arrPtr[i] = val;
}

// Copy Constructor:
FloatArr::FloatArr(const FloatArr& src)
{
   max = src.max;
   cnt = src.cnt;
   arrPtr = new float[max];

   for( int i = 0; i < cnt; i++ )
      arrPtr[i] = src.arrPtr[i];
}

// Destructor:
FloatArr::~FloatArr()
{
   delete[] arrPtr;
}

// Assignment:
FloatArr& FloatArr::operator=( const FloatArr& src )
{
   if( this != &src )              // No self assignment!
   {
      max = src.max; 
      cnt = src.cnt;

      delete[] arrPtr;             // Release memory,
      arrPtr = new float[max];     // reallocate and
      for( int i=0; i < cnt; i++)  // copy elements.
        arrPtr[i] = src.arrPtr[i];
   }
   return *this;
}

// Subscript operator for objects, that are not const:
float& FloatArr::operator[]( int i ) 
{
   if( i < 0 || i >= cnt )       // Range checking
   {
      cerr << "\n class FloatArr: Out of Range! "; 
      exit(1);
   }
   return arrPtr[i];
}

// Subscript operator for const objects:
float FloatArr::operator[]( int i ) const
{
   if( i < 0 || i >= cnt )       // Range checking
   {
      cerr << "\n class FloatArr: Out of Range! "; 
      exit(1);
   }
   return arrPtr[i];
}

bool FloatArr::append( float val) 
{ 
   if(cnt < max)
   { 
      arrPtr[cnt++] = val;
      return true;
   }
   else                  // Enlarge the array!
      return false;      
}

bool FloatArr::remove(int pos)
{ 
   if( pos >= 0 && pos < cnt)
   {
      for( int i = pos; i < cnt-1; ++i) 
         arrPtr[i] = arrPtr[i+1];
      --cnt;
      return true;
   }
   else
      return false;
}
