//  ball1.cpp
//  Simulates a bouncing ball
//  Notice: Terminate the program by interrupt key (^C).
//  ----------------------------------------------------
//  To activate the control characters, a corresponding
//  screen driver has to be loaded.
//  For Windows 9x this is done by entering the following
//  line contained in the file CONFIG.SYS:
//
//         DEVICE=C:\Windows\Command\Ansi.sys
// -----------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

#define DELAY 10000000 // Output delay

#define CLS (cout << "\033[2J") // Clear sceen

#define LOCATE(r, c) (cout << "\033[" << r << ';' << c << 'H')
// Position the cursor in row r and column c

int main()
{
  int x = 2, y = 3, dx = 1, speed = 0;
  string floor(79, '-'),
      header = "****  JUMPING BALL  ****";

  CLS;
  LOCATE(1, 25);
  cout << header;
  LOCATE(25, 1);
  cout << floor;

  while (true) // Let the ball "always" bounce
  {            // Terminate by interrupt key (^C)

    LOCATE(y, x);
    cout << 'o'; // Show the ball
    for (long wait = 0; wait < DELAY; ++wait)
      ;

    if (x == 1 || x == 79)
      dx = -dx; // Bounce off a wall?

    if (y == 24) // On the floor?
    {
      speed = -speed;
      if (speed == 0)
        speed = -7; // Restart
    }
    speed += 1; // Acceleration = 1

    LOCATE(y, x);
    cout << ' '; // Clear output
    y += speed;
    x += dx; // New Position
  }
}
