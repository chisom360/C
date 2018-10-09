// -----------------------------------------------------
// floatArr.cpp 
// Implementing the methods of FloatArr.
// -----------------------------------------------------

#include "floatArr.h"

// ---  Constructors  ---
FloatArr::FloatArr( int n )
{
    max = n;   cnt = 0;        // Sets max and cnt.
    arrPtr = new float[max];   // Allocates memory
}

FloatArr::FloatArr(int n, float val)
{
   max = cnt = n;
   arrPtr  = new float[max];
   for( int i=0; i < cnt; ++i) 
        arrPtr[i] = val;
}
 
FloatArr::FloatArr(const FloatArr& src)
{
   max = src.max;
   cnt = src.cnt;
   arrPtr = new float[max];

   for( int i = 0; i < cnt; i++ )
     arrPtr[i] = src.arrPtr[i];
}

// --- Destructor ---
FloatArr::~FloatArr()
{
   delete[] arrPtr;
}

// Private function to help enlarge the array.
void FloatArr::expand( int newSize)
{
   if( newSize == max)
      return;

   max = newSize;
   if( newSize < cnt)
      cnt = newSize;

   float *temp = new float[newSize];
   for( int i = 0; i < cnt; ++i)
      temp[i] = arrPtr[i];

   delete[] arrPtr;
   arrPtr = temp;
}

FloatArr& FloatArr::operator=( const FloatArr& src )
{
   if( this != &src )              // No self assignment!
   { 
      max = src.max; 
      cnt = src.cnt;

      delete[] arrPtr;             // Release memory,

      arrPtr = new float[max];     // reallocate,

      for( int i=0; i < cnt; i++)  // copy elements.
        arrPtr[i] = src.arrPtr[i];
   }
   return *this;
}
 
float& FloatArr::operator[]( int i ) throw(BadIndex)
{
   if( i < 0 || i >= cnt )  throw BadIndex(i);
   return arrPtr[i];
}
float FloatArr::operator[]( int i ) const throw(BadIndex)
{
   if( i < 0 || i >= cnt )  throw BadIndex(i);
   return arrPtr[i];
}

// Append a float value or an array of floats.
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
   int count = v.cnt;             // Necessary if
                                  // v == *this.
   for( int i=0; i < count; ++i)
     arrPtr[cnt++] = v.arrPtr[i];
}

// Inserts a float value or an array of floats.
void FloatArr::insert(float val, int pos) throw(BadIndex)
{
   insert( FloatArr(1, val), pos);
}

void FloatArr::insert( const FloatArr& v, int pos) throw( BadIndex )
{
   if( pos < 0 || pos > cnt)         // Append is also possible.
      throw BadIndex(pos);

   if( max < cnt + v.cnt)
      expand(cnt + v.cnt);

   int i;
   for( i = cnt-1; i >= pos; --i)    // Shift up from
      arrPtr[i+v.cnt] = arrPtr[i];   // position pos.

   for( i = 0; i < v.cnt; ++i)       // Fill the gap.
      arrPtr[i+pos] = v.arrPtr[i];

   cnt = cnt + v.cnt;
}

// To delete
void FloatArr::remove(int pos) throw(BadIndex)
{ 
   if( pos >= 0 && pos < cnt)
   {
      for( int i = pos; i < cnt-1; ++i) 
         arrPtr[i] = arrPtr[i+1];
      --cnt;
   }
   else
     throw BadIndex(pos);
}

