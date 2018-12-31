#include <iostream>
#include <string>
#include "karel.h"

int main()
{
  ur_Robot karel(1, 1, east, 10);
  ur_Robot karel2(1, 1, east, 0);

  // ur_Robot.printAllRobots();
  //ur_Robot.printWorld();

  karel.move();
  karel.putBeeper();
  karel.move();
  karel.putBeeper();
  karel.putBeeper();
  karel.move();
  karel.putBeeper();
  karel.turnLeft();
  karel.move();
  karel.move();
  karel.turnOff();

  karel.print();

  // ur_Robot.printAllRobots();
  //ur_Robot.printWorld();

  karel2.move();
  karel2.pickBeeper();
  karel2.move();
  karel2.pickBeeper();
  karel2.move();
  karel2.pickBeeper();
  karel2.turnLeft();
  karel2.turnLeft();
  karel2.turnLeft();
  karel2.move();
  karel2.move();

  karel.printAllRobots();
  karel.printWorld();

  karel2.turnOff();

  karel2.turnLeft();
  karel2.turnLeft();
  karel2.move();
  karel2.move();

  karel.printAllRobots();
  //ur_Robot.printWorld();

  return 0;

  return 0;
}
