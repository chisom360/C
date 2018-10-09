// ------------------------------------------------------
// myMacros.h 
// Headerfile contains the Macros 
// ABS, MIN, MAX, CLS, LOCATE, COLOR, NORMAL, INVERS
// and symbolic constants for colors.
// ------------------------------------------------------

#ifndef _MYMACROS_
#define _MYMACROS_

#include <iostream>
using namespace std;

// ------------------------------------------------------
// Macro ABS
// Call:  ABS( val) 
// Returns the absolute value of val
#define ABS(a) ( (a) >= 0 ? (a) : -(a))

// ------------------------------------------------------
// Macro MIN
// Call:  MIN(x,y) 
// Returns the minimum of x and y
#define MIN(a,b) ( (a) <= (b) ? (a) : (b)) 

// ------------------------------------------------------
// Macro MAX
// Call:  MAX(x,y) 
// Returns the maximum of x and y
#define MAX(a,b) ( (a) >= (b) ? (a) : (b)) 


// ------------------------------------------------------
// Macros controlling the screen
// ------------------------------------------------------
// Macro CLS
// Call:  CLS; 
// Clears the screen 
#define CLS   (cout << "\033[2J") 

// ------------------------------------------------------
// Macro LOCATE
// Call:  LOCATE(zeile, spalte); 
// Positions the cursor to (row,column).
// (1,1) is the upper left corner.
#define LOCATE(r,c) (cout <<"\033["<< (r) <<';'<<(c)<<'H')
 
// ------------------------------------------------------
// Macro COLOR
// Call:  COLOR(foreground, background); 
// Sets the foreground and background color 
// for the following output.
#define COLOR( f, b) (cout << "\033[1;3"<< (f) \
                           <<";4"<< (b) <<'m' << flush)
//  1: light foreground
// 3x: foreground x
// 4x: background x

// Color values for the makro COLOR
// To call e.g.: COLOR( WHITE,BLUE);
#define BLACK    0
#define RED      1
#define GREEN    2
#define YELLOW   3
#define BLUE     4
#define MAGENTA  5
#define CYAN     6
#define WHITE    7

// ------------------------------------------------------
// Macro INVERS
// Call:  INVERS; 
// The following output is inverted.
#define INVERS  (cout << "\033[7m")

// ------------------------------------------------------
// Macro NORMAL
// Call:  NORMAL; 
// Sets the screen attributes on default values.
#define NORMAL  (cout << "\033[0m")

#endif     //  _MYMACROS_
