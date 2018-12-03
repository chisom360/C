#ifndef KarelWorld_H
#define KarelWorld_H
#include "Intersect.h"

class karelWorld
{
  private:
    Intersection street;

  public:
    karelWorld();
    int hasCorner(int street, int avenue);
    int getBeeperCount(int street, int avenue);
    int incrementBeeperCount(int street, int avenue);
    int decrementBeeperCount(int street, int avenue);
    int wallToNorth(int street, int avenue);
    int wallToSouth(int street, int avenue);
    int wallToEast(int street, int avenue);
    int wallToWest(int street, int avenue);

    void print();
};

#endif