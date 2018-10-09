// ------------------------------------------------------
// floatArr.h : Dynamic arrays of floating-point numbers.
// ------------------------------------------------------
#ifndef _FLOATARR_
#define _FLOATARR_

#include <iostream>
using namespace std;

class FloatArr
{
   private:
     float* arrPtr;        // Dynamic member
     int max;              // Maximum quantity without 
                           // reallocation new storage.
     int cnt;              // Number of present array elements 

     void expand( int newMax);   // Helps enlarge the array

   public:
     FloatArr( int n = 256 );         // Constructor
     FloatArr( int n, float val);
     ~FloatArr();                     // Destructor

     FloatArr(const FloatArr& src);   // Copy constructor
     FloatArr& operator=( const FloatArr&); // Assignment

     int  length() const { return cnt; }

     float& operator[](int i);        // Subscript operator.

     float  operator[](int i) const;

     // Methods to append a floating-point number 
     // or an array of floating-point numbers:
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

     // Methods to insert a floating-point number 
     // or an array of floating-point numbers:
     bool insert( float val, int pos); 
     bool insert( const FloatArr& v, int pos ); 

     bool remove(int pos);     // Delete at position pos.
     // To output the array
     friend ostream& operator<<( ostream& os, const FloatArr& v);
};

#endif   // _FLOATARR_
