#ifndef KarelWorld_H
#define KarelWorld_H
#include "Intersect.h"
#include <vector>

class karelWorld
{
private:
  std::vector<Intersection> karelIntersection;

public:
  karelWorld();
  int hasCorner(int street, int avenue);
  int getBeeperCount(int street, int avenue);
  int incrementBeeperCount(int street, int avenue);
  int decrementBeeperCount(int street, int avenue);
  bool wallToNorth(int street, int avenue);
  bool wallToSouth(int street, int avenue);
  bool wallToEast(int street, int avenue);
  bool wallToWest(int street, int avenue);

  void print();
};

#endif
