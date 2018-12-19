#include <iostream>
#include <string>
#include "karel.h"

int main()
{
  ur_Robot karel(1, 1, East, 10);

  karel.print();
  karel.move();
  karel.pickBeeper();
  karel.move();
  karel.print();

  karel.turnLeft();
  karel.move();
  karel.putBeeper();
  karel.putBeeper();
  karel.turnOff();
  karel.print();

  return 0;
}
