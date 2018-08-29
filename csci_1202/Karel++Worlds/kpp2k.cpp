#include "world.hpp"

int main(int argc, char*argv[])
{
  robotWorld.initWorld(argv[1]);
//  jjp_World::readWorld(argv[1]);

  robotWorld.writeRoches();
//  jjp_World::writeRoches();

  return 0;
}
