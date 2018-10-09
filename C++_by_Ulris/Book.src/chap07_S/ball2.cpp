// --------------------------------------------------- 
//  ball2.cpp
//  Simulates a jumping ball
// --------------------------------------------------- 
//  Notice: Terminate the program by Ctrl+C.
//  --------------------------------------------------
//  To activate the control characters, 
//  a corresponding screen driver has to be loaded.
//  Under Windows 9x this is done by the following
//  line containe in the file CONFIG.SYS:
//         DEVICE=C:\Windows\Command\Ansi.sys
// --------------------------------------------------- 

#include <iostream>
#include <string>
using namespace std;
#include <conio.h>             // For kbhit() und getch()
#include "myMacros.h"
 
#define  ESC   27            // ESC terminates the program
unsigned long delay = 5000000;         // Delay for output

int main()
{
   int x = 2, y = 2, dx = 1, speed = 0;
   bool end = false;
   string floor(80, '-'),
          header   = "****  BOUNCING BALL ****",
          commands = "[Esc] = Terminate     "
                     "[+] = Speed up     [-] = Slow down";

   COLOR(WHITE,BLUE);
   CLS;
   LOCATE(1,25);  cout << header;
   LOCATE(24,1);  cout << floor;
   LOCATE(25,10); cout << commands;

   while( !end)        // As long as the flag is not set
   {              
     LOCATE(y,x);  cout << 'o';         // Show the ball
     for( long wait = 0; wait < delay; ++wait)
       ;
     if(x == 1 || x == 79) dx = -dx;     // Bounce off a wall?
     if( y == 23 )                       // On the floor?
     {
       speed = - speed;
       if( speed == 0 ) speed = -7;      // Kick
     }
     speed += 1;                         // Acceleration = 1

     LOCATE(y,x); cout <<  ' ';          // Clear screen
     y += speed;  x += dx;               // New position

     if( kbhit() != 0 )                  // Key pressed?
     {
        switch(getch())                  // Yes 
        {
          case '+':  delay -= delay/5;   // Speed up 
                     break;
          case '-':  delay += delay/5;   // Slow down
                     break;
          case ESC:  end = true;         // Terminate 
        }
     }
   }
   NORMAL;  CLS;
   return 0;
}
