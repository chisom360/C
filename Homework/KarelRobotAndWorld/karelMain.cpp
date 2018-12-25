#include <iostream>
#include <string>
#include "karel.h"

int main()
{
  ur_Robot karel(5, 7, north, 10);
  karel.print();
  karel.move();
  karel.printWorld();
  /*
  karel.printWorld();
  karel.pickBeeper();
  karel.printWorld();
  */
  karel.print();

  return 0;
}
