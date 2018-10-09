// ------------------------------------------------------
// array.h
// Use of class templates to represent arrays.
// ------------------------------------------------------
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <iomanip>
using namespace std;

class BadIndex
{
  private:
    int index;
  public:
    BadIndex(int i):index(i){}
    int getBadIndex() const { return index; }
};

class OutOfRange {  /* Without data members*/ };

template <class T, int n = 256>
class Array
{
   private:
     T   arr[n];          // The array
     int cnt;             // Current number of elements
 
   public:
     Array( ){ cnt = 0;}
     Array(int n, const T& val );

     int  length() const { return cnt; }
     int  size()   const { return n; }

     T& operator[](int i) throw(BadIndex)
     {
        if( i < 0 || i >= cnt ) throw BadIndex(i);
        return arr[i];
     }
     const T&  operator[](int i) const throw(BadIndex)
     {
        if( i < 0 || i >= cnt ) throw BadIndex(i);
        return arr[i];
     }
 

     Array& operator+=( float val) throw(OutOfRange)
     {
        append( val);   return *this;
     }

     Array& operator+=(const Array& v)  throw(OutOfRange)
     {
        append(v);   return *this;
     }

     void append( T val) throw(OutOfRange);
     void append( const Array& v) throw(OutOfRange);

     void insert( T val, int pos)
                             throw(BadIndex, OutOfRange);
     void insert( const Array& v, int pos )
                             throw(BadIndex, OutOfRange);

     void remove(int pos) throw(BadIndex);
};

template <class T, int n >
Array<T,n>::Array(int m, const T& val ) 
{ 
   cnt = m;
   for(int i=0; i < cnt; i++ )
      arr[i] = val;
}

template <class T, int n >
void Array<T,n>::append( T val) throw(OutOfRange)
{ 
   if( cnt < n)
       arr[cnt++] = val;
   else
       throw OutOfRange();
}

template <class T, int n >
void Array<T,n>::append( const Array<T,n>& v) throw(OutOfRange)
{ 
   if( cnt + v.cnt > n)            // Not enough space.
      throw OutOfRange();
    
   int count = v.cnt;              // Necessary if 
                                   // v == *this
   for( int i=0; i < count; ++i)
     arr[cnt++] = v.arr[i];
}

template <class T, int n >
void Array<T,n>::insert( T val, int pos)
                               throw(BadIndex, OutOfRange)
{   insert( Array<T,n>(1,val), pos);
}

template <class T, int n >
void Array<T,n>::insert( const Array<T,n>& v, int pos ) 
                               throw(BadIndex, OutOfRange)
{
   if( pos < 0 || pos >= cnt)
      throw BadIndex();              // Invalid position.

   if( n < cnt + v.cnt)
      throw OutOfRange();
 
   int i;
   for( i = cnt-1; i >= pos; --i)    // Shift up
      arr[i+v.cnt] = arr[i];         // starting at pos.

   for( i = 0; i < v.cnt; ++i)       // Fill the gap.
      arr[i+pos] = v.arr[i];
   cnt = cnt + v.cnt;
}

template <class T, int n >
void Array<T,n>::remove(int pos) throw(BadIndex)
{ 
   if( pos >= 0 && pos < cnt)
   {
      for( int i = pos; i < cnt-1; ++i) 
         arr[i] = arr[i+1];
      --cnt;
   }
   else  throw BadIndex(pos);
}

template <class T, int n >
ostream& operator<<(ostream& os, const Array<T,n>& v)
{
   int w = os.width();       // Save the field width
 
   for( int i = 0; i < v.length(); ++i)
   {
      os.width(w);    os << v[i];
   }
   os << endl;
   return os;
}
#endif

/*----
// ------------------------------------------------------
// array.h
// Representing arrays by class templates.
// ------------------------------------------------------
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <iomanip>
using namespace std;

class BadIndex
{
  private:
    int index;
  public:
    BadIndex(int i):index(i){}
    int getBadIndex() const { return index; }
};

class OutOfRange {  /* Without data elements * / };

template <class T, int n = 256>
class Array
{
   private:
     T   arr[n];          // The array
     int cnt;             // Current number of elements
 
   public:
     Array( ){ cnt = 0;}
     Array(int n, const T& val );

     int  length() const { return cnt; }
     int  size()   const { return n; }

     T& operator[](int i) throw(BadIndex)
     {
        if( i < 0 || i >= cnt ) throw BadIndex(i);
        return arr[i];
     }
     const T&  operator[](int i) const throw(BadIndex)
     {
        if( i < 0 || i >= cnt ) throw BadIndex(i);
        return arr[i];
     }
 
     Array& operator+=( float val) throw(OutOfRange)
     {
        append( val);   return *this;
     }

     Array& operator+=(const Array& v)  throw(OutOfRange)
     {
        append(v);   return *this;
     }

     void append( T val) throw(OutOfRange);
     void append( const Array& v) throw(OutOfRange);

     void insert( T val, int pos)
                             throw(BadIndex, OutOfRange);
     void insert( const Array& v, int pos )
                             throw(BadIndex, OutOfRange);

     void remove(int pos) throw(BadIndex);

};

template <class T, int n >
Array<T,n>::Array(int n, const T& val ) 
{ 
   cnt = n;
   for(int i=0; i < cnt; i++ )
      arr[i] = val;
}

template <class T, int n >
void Array<T,n>::append( T val) throw(OutOfRange)
{ 
   if( cnt < n)
       arr[cnt++] = val;
   else
       throw OutOfRange();
}


template <class T, int n >
void Array<T,n>::append( const Array<T,n>& v) throw(OutOfRange)
{ 
   if( cnt + v.cnt > n)            // Not enough space
      throw OutOfRange();
    
   int count = v.cnt;              // necessary if 
                                   // v == *this
   for( int i=0; i < count; ++i)
     arr[cnt++] = v.arr[i];
}

template <class T, int n >
void Array<T,n>::insert( T val, int pos)
                               throw(BadIndex, OutOfRange)
{
   insert( Array<T,n>(1,val), pos);
}

template <class T, int n >
void Array<T,n>::insert( const Array<T,n>& v, int pos ) 
                               throw(BadIndex, OutOfRange)
{
   if( pos < 0 || pos >= cnt)
      throw BadIndex();           // invalid position.

   if( n < cnt + v.cnt)
      throw OutOfRange();
 
   int i;
   for( i = cnt-1; i >= pos; --i)    // To shift up
      arr[i+v.cnt] = arr[i];         // starting at pos.

   for( i = 0; i < v.cnt; ++i)       // To fill the gap.
      arr[i+pos] = v.arr[i];
   cnt = cnt + v.cnt;
}

template <class T, int n >
void Array<T,n>::remove(int pos) throw(BadIndex)
{ 
   if( pos >= 0 && pos < cnt)
   {
      for( int i = pos; i < cnt-1; ++i) 
         arr[i] = arr[i+1];
      --cnt;
   }
   else  throw BadIndex(pos);
}

template <class T, int n >
ostream& operator<<( ostream& os, const Array<T,n>& v)
{
   int w = os.width();        // Feldbreite merken.
   
   for( int i = 0; i < v.length(); ++i)
   {
      os.width(w);    cout << v[i];
   }
   os << endl;
   return os;
}

#endif
*/