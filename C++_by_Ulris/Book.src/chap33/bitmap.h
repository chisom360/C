//  bitmap.h : Defines the template Bitmap<N>
//             representing raster graphics.
// -------------------------------------------------
#ifndef _BITMAP_
#define _BITMAP_

#include <bitset>
#include <stdexcept>
using namespace std;

template <int N>
class Bitmap : public bitset<N>
{
   private:
      int lines, cols; // Number of rows and colums
      int ax, ay;      // Current cursor position

   public:
      Bitmap(int l, int c);
      void moveTo(int x, int y);
      void lineTo(int x, int y);
};

template <int N>
Bitmap<N>::Bitmap(int l, int c)
{
   if (l*c <= N)
   {
      reset();                  // Set all bits to 0
      lines = l; cols = c;      // Rows and columns
      ax = 0; ay = 0;           // Current position
   }
   else
      throw invalid_argument("Invalid argument \n");
}

template <int N>
void Bitmap<N>::moveTo(int x, int y)
{
  if( x >= 0 && x < lines && y >= 0 && y < cols)
  { 
     ax = x;  ay = y;
  }
  else
     throw invalid_argument("Invalid argument\n");
}

// ---------------------------------------------------
// Method lineTo() uses the Bresenham algorithm.
//
template <int N>
void Bitmap<N>::lineTo(int x, int y)
{
  if( x >= 0 && x < lines && y >= 0 && y < cols)
  {
    int savex = x, savey = y;

    if(ax > x) // Draw in ascending x-direction
    {          // => possibly swap (ax,ay) and (x,y) 
      int temp = ax; ax = x; x = temp;
      temp = ay; ay = y; y = temp;        
    }
    int dx = x - ax, dy = y - ay;
    int xinc = 1, yinc;        // Increment 

    if( dy < 0)                // Gradient < 0 ?
    { yinc = -1; dy = -dy;}    // Decrement y
    else yinc = 1;             // or else increment.

    int count = dx + dy;       // Number of pixels to be set

    int d = (dx - dy)/2;       // Measurement of deviation 
                               // off the line.
    while( count-- > 0)
    {
      int ai = ax * cols + ay; // Index in the bitset
      set(ai);                 // Set the bit

      if( d < 0)               // Next pixel in
      { ay += yinc;  d += dx; }    // y-direction
      else                         // or else in
      { ax += xinc;  d -= dy; }    // x-direction
    }

    ax = savex; ay = savey;    // Current cursor position
  }
  else throw invalid_argument("Invalid argument\n");
}

#endif
