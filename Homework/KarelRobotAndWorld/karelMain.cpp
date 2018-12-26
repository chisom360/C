#include <iostream>
#include <string>
#include "karel.h"

int main()
{
  ur_Robot karel(10, 2, east, 10);
  ur_Robot karel2(1, 15, north, 0);
  ur_Robot karel3(3, 5, north, 0);

  karel.printAllRobots();

  return 0;
}
