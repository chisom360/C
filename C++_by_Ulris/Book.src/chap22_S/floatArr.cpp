// -----------------------------------------------------
// FloatVek.cpp
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

//  ---  The new functions  --- 

// Private auxiliary function to enlarge the array.
void FloatArr::expand( int newMax)
{
   if( newMax == max)
      return;

   max = newMax;
   if( newMax < cnt)
      cnt = newMax;
   float *temp = new float[newMax];
   for( int i = 0; i < cnt; ++i)
      temp[i] = arrPtr[i];

   delete[] arrPtr;
   arrPtr = temp;
}

// Append floating-point number or an array of floats.
void FloatArr::append( float val)
{ 
   if( cnt+1 > max)
       expand( cnt+1);
 
   arrPtr[cnt++] = val;
}

void FloatArr::append( const FloatArr& v)
{ 
   if( cnt + v.cnt > max)
       expand( cnt + v.cnt);
   
   int count = v.cnt;            // Necessary if v == *this
                                 
   for( int i=0; i < count; ++i)
     arrPtr[cnt++] = v.arrPtr[i];
}

// Insert a float or an array of floats
bool FloatArr::insert( float val, int pos)
{
   return insert( FloatArr(1,val), pos);
}

bool FloatArr::insert( const FloatArr& v, int pos )
{
   if( pos < 0 || pos >= cnt)
      return false;              // Invalid position

   if( max < cnt + v.cnt)
      expand(cnt + v.cnt);

   int i; 
   for( i = cnt-1; i >= pos; --i)    // Shift up 
      arrPtr[i+v.cnt] = arrPtr[i];   // starting at pos

   for( i = 0; i < v.cnt; ++i)       // Fill gap. 
      arrPtr[i+pos] = v.arrPtr[i];

   cnt = cnt + v.cnt;

   return true;
}

// To delete
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

// Output the array
ostream& operator<<( ostream& os, const FloatArr& v)
{
   int w = os.width();            // Save field width.
   for( float *p = v.arrPtr; p < v.arrPtr + v.cnt; ++p)
   {
      os.width(w);    os << *p;
   }
   return os;
}
