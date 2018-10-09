// floatArr.h : Dynamic array of floats.
// ---------------------------------------------------
#ifndef _FLOATARR_
#define _FLOATARR_

class FloatArr
{
   private:
     float* arrPtr;      // Dynamic member
     int max;            // Maximum quantity without 
                         // reallocation new storage.
     int cnt;            // Number of array elements 

   public:
     FloatArr( int n = 256 );         // Constructor
     FloatArr( int n, float val);
     ~FloatArr();                     // Destructor

     FloatArr(const FloatArr& src);   // Copy constructor
     FloatArr& operator=( const FloatArr&); // Assignment

     int  length() const { return cnt; }

     float& operator[](int i);        // Subscript operator.

     float  operator[](int i) const;

     bool append(float val);          // Append value val.
     bool remove(int pos);            // Delete position pos.
};

#endif   // _FLOATARR_
