#ifndef KAREL_H
#define KAREL_H
#include "KarelWorld.h"
#include <iostream>
#include <string>

enum direction
{
  east = 1,
  north = 2,
  west = 3,
  south = 4,
};

class ur_Robot
{
private:
  direction locateRobot;
  int westWall = 1;
  int southWall = 1;
  int KarelAvenue;
  int KarelStreet;
  int beeperCount = 0;
  bool karelState = true;
  static karelWorld KarelAndWorld;

  std::string setDirectionString = " ";

public:
  //ur_Robot constructor
  ur_Robot(int xCoordinate, int yCoordinate, direction locateKarel, int BeepCnt);
  void print();
  void turnLeft();
  void move();
  int putBeeper();
  int pickBeeper();
  bool turnOff();
  void locateKarel();

  //getter methods
  bool getKarelState();
  int getKarelBeeperCount();
  int getKarelStreet();
  int getKarelAvenue();
  std::string getDirectionString();
  karelWorld getKarelAndWorld()
  {
    return KarelAndWorld;
  }
};

#endif