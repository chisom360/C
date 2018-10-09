// ------------------------------------------------------
// floatArr.h : Represents dynamic float arrays.
// Methods throw exceptions for an invalid index.
// ------------------------------------------------------
#ifndef _FLOATARR_
#define _FLOATARR_

#include <iostream>
using namespace std;

class BadIndex
{
   private:
     int index;
   public:
     BadIndex(int i){index = i;}
     int getBadIndex() const {return index;}
};

class FloatArr
{
   private:
     float* arrPtr;    // Dynamic member
     int max;          // Maximum number without
                       // reallocating more memory.
     int cnt;          // Current number of elements.

     void expand( int newSize);      // Function to help
                                     // enlarge the array.
   public:
     FloatArr( int n = 256 );        // Constructors
     FloatArr( int n, float wert);
     FloatArr(const FloatArr& src);

     ~FloatArr();                    // Destructor

     FloatArr& operator=( const FloatArr&);  // Assignment

     int  length() const { return cnt; }
 
      // Subscript operators:
     float& operator[](int i) throw(BadIndex); 
     float operator[](int i) const  throw(BadIndex); 

     // Methods to append a float value 
     // or an array of floats:
     void append( float val);
     void append( const FloatArr& v);

     FloatArr& operator+=( float val)
     {
         append( val);   return *this;
     }
     FloatArr& operator+=( const FloatArr& v) 
     {
         append(v);   return *this;
     }
 
     // Methods to insert a float value 
     // or an array of float values:
    void insert( float val, int pos)  throw(BadIndex); 
    void insert(const FloatArr& v,int pos)  throw(BadIndex);

    void remove(int pos) throw(BadIndex);  // Remove at pos.

    // Output the array
    friend ostream& operator<<( ostream& os, const FloatArr& v)
    {
      int w = os.width();        // Save field width.
      for( float *p = v.arrPtr;  p < v.arrPtr + v.cnt;  ++p)
      {
         os.width(w);  os << *p;
      }
      return os;
    }
};

#endif   // _FLOATARR_
