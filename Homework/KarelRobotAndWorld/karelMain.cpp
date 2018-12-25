#include <iostream>
#include <string>
#include "karel.h"

int main()
{
  ur_Robot karel(10, 10, east, 10);
  karel.print();
  karel.printWorld();
  karel.putBeeper();
  karel.printWorld();
  karel.print();
  std::cout << karel.getKarelBeeperCount();

  return 0;
}
