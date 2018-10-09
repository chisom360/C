// input.cpp: The function input() reads characters 
//            from the keyboard and appends '\0'. 
//            The input can be corrected with backspace.
// Arguments: 1. Pointer to the input buffer.
//            2. Maximum number of characters to be read
//            3. Optional arguments: Characters that
//               terminate the input.
//               This list has to end with CR = '\r'!
// Returns:   Character which breaks the input.
// ---------------------------------------------------
#include <stdarg.h>
#include <conio.h>     // For getch() and putch()

int input(char *buffer, int max,... )
{
  int c, breakc;    // Current character, character to
                    // break with.
  int nc = 0;       // Number of characters read. 
  va_list argp;     // Pointer to the following arguments.
  
  while(true)
  {
    *buffer = '\0';
    if( ( c = getch()) == 0)    // Read a character.
        c = getch() + 256;      // For special keys: 
                                // Extended code + 256.

    va_start(argp, max);        // Initialze argp.

    do                   // Compare with break characters:
      if( c == (breakc = va_arg(argp,int)) )
         return(breakc);
    while( breakc != '\r');

    va_end( argp);

    if( c == '\b' &&  nc > 0)      // Backspace? 
    {
        --nc,  --buffer;
        putch(c);  putch(' '); putch(c);
    }
    else if( c >= 32  &&  c <= 255  &&  nc < max )
    {                   // Place character into the buffer 
       ++nc,  *buffer++ = c;  putch(c);     // and output.
    }
    else if( nc == max)       // Is end of buffer reached? 
       putch('\a');           // Beep. 
  }
}


#include <iostream>
using namespace std;

int main()
{
    char word[11];
    int  cBreak = 0;

    cout << "\nPlease enter a word "
         << "\n(Break with tab, blank, esc or return):" 
         << endl;
    cBreak = input(word, 10, '\t', ' ', 27, '\r'); 

    cout << "\n\nAnd here is your input: \n";
    cout << word << endl;

    cout << "Code of character that terminates your input: "
         << cBreak << endl;

    return 0;
}
