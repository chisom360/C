#ifndef KarelWorld_H
#define KarelWorld_H
#include "Intersect.h"
#include <vector>
#include <algorithm>

class karelWorld
{
private:
  //std::vector<Intersection> list; //container for the newly created world(Karel intersection container)

public:
  //karelWorld();
  karelWorld();
  std::vector<Intersection> list; //container for the newly created world(Karel intersection container)
  karelWorld(std::vector<Intersection> IntersectionList);
  bool hasCorner(int street, int avenue);
  int getBeeperCount(int street, int avenue);
  int incrementBeeperCount(int street, int avenue);
  int decrementBeeperCount(int street, int avenue);
  bool wallToNorth(int street, int avenue);
  bool wallToSouth(int street, int avenue);
  bool wallToEast(int street, int avenue);
  bool wallToWest(int street, int avenue);
  void print2();                      // print all the corners
  void print(int street, int avenue); //prints information about a specfic street and corner

  void print();
};

#endif
