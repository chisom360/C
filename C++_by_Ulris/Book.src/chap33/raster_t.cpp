// --------------------------------------------------------- 
// raster_t.cpp: Tests the Bresenham algorithm  
//               in text mode with a bitmap of 24*80 pixels.
// --------------------------------------------------------- 

#include <iostream>
using namespace std;

#include "bitmap.h"

const int LINES=24, COLS=60;

int main()
{

   Bitmap<LINES*COLS> bm(LINES,COLS);

   try
   {
      bm.moveTo(0, 0);      bm.lineTo(LINES-1,COLS-1);
      bm.moveTo(0,COLS-1);  bm.lineTo(LINES-1, 0);
   }
   catch(invalid_argument& e)
   {
      cerr << e.what(); 
      exit(1);
   }

   int size = bm.size();

   for( int i = 0; i < size; i++)
   {
      cout << (bm[i] ? '*' : ' ');

      if( (i+1) % COLS == 0 ) 
         cout << endl;
   }

   return 0;
}
