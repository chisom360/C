#include <iostream>
#include <string>
#include "karel.h"
#include "KarelWorld.h"

int main()
{
  ur_Robot karel(1, 1, east, 10);

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
  karel.getKarelAndWorld();

  return 0;
}
