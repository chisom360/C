// ----------------------------------------------------------------------
// console.h  
//
// Declares the functions  
//        cls(), setCursor(), setColor()
// which control console screen output for Windows 95, 98, 2000 and NT.
// These functions are defined in console.cpp.
// 
// In addition, symbolic constants are defined to set colors 
// Author: Peter Prinz
// ----------------------------------------------------------------------

#include <windows.h> 

// Symbolic constants for foreground and background colors
// The following constants are already defined (via windows.h):
//   FOREGROUND_RED, FOREGROUND_GREEN, FOREGROUND_BLUE, FOREGROUND_INTENSITY
//   BACKGROUND_RED, BACKGROUND_GREEN, BACKGROUND_BLUE, BACKGROUND_INTENSITY

// And several combinations: 
#define BACKGROUND_CYAN   (BACKGROUND_GREEN | BACKGROUND_BLUE)
#define BACKGROUND_WHITE  (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE)
#define BACKGROUND_YELLOW (BACKGROUND_RED | BACKGROUND_GREEN)

#define FOREGROUND_CYAN   (FOREGROUND_GREEN | FOREGROUND_BLUE |  FOREGROUND_INTENSITY)
#define FOREGROUND_YELLOW (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define FOREGROUND_WHITE  (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)


// Prototypes of functions  defined in console.cpp

bool cls();
bool setCursor( int line, int column);
bool setColor( int color );

void cursorOff();
void cursorOn();
