// ----------------------------------------------------------------------
// console.cpp   
// Defines functions to control console screen output
// Author: Peter Prinz
// ----------------------------------------------------------------------

#include "console.h" 

static HANDLE hStdout; 
static CONSOLE_SCREEN_BUFFER_INFO csbInfo; 

////////////////////////////////////////////////////////////////////////
// Function setCursor()  sets the cursor to the position passed as argument.

bool setCursor( int line, int column)
{
    COORD dwCursorPos = {line, column};

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    return SetConsoleCursorPosition(hStdout, dwCursorPos) != 0;
}

////////////////////////////////////////////////////////////////////////
// Function setColor()  sets the foreground and background color passed as argument.

bool setColor( int color)
{
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    return SetConsoleTextAttribute(hStdout, (WORD)color) != 0;
}

////////////////////////////////////////////////////////////////////////
// Function cls()  clears the screen and sets the cursor to home position

bool cls()
{
    COORD home = { 0, 0 };            // Home position
    DWORD dwCellsWritten;             // Number of written char cells 
    DWORD dwConSize;                  // Number of characters in console output buffer

    // Gets the buffer size and the current attribute
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    GetConsoleScreenBufferInfo(hStdout, &csbInfo);
    
    dwConSize = csbInfo.dwSize.X * csbInfo.dwSize.Y;
 
    // Fills the buffer with blanks
    if( ! FillConsoleOutputCharacter(hStdout, (TCHAR)' ', dwConSize,
                                     home, &dwCellsWritten) )
        return false;

    // Sets attributes:
    if( ! FillConsoleOutputAttribute(hStdout, csbInfo.wAttributes, dwConSize,
                                     home, &dwCellsWritten) )
        return false;

    // Sets the cursor to home position 
    if( ! SetConsoleCursorPosition(hStdout, home) )
        return false;

    return true;
}

////////////////////////////////////////////////////////////////////////
// Function cursorOff() : Hides the cursor.

void cursorOff()
{
    CONSOLE_CURSOR_INFO cursorInfo;   
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 

    GetConsoleCursorInfo( hStdout, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo( hStdout, &cursorInfo);
}

////////////////////////////////////////////////////////////////////////
// Function cursorOn() : Makes the cursor visible, again.

void cursorOn()
{
    CONSOLE_CURSOR_INFO cursorInfo;   
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 

    GetConsoleCursorInfo( hStdout, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo( hStdout, &cursorInfo);
}
