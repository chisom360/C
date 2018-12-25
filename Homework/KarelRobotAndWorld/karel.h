#ifndef KAREL_H
#define KAREL_H
#include "KarelWorld.h"
#include "KarelWorldBuilder.h"
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
  std::string setDirectionString = " ";
  static int &getNumberOfRobotInTheWorld()
  {
    static int counter = 0;
    return counter;
  }

public:
  static karelWorld KarelAndWorld;
  int printAllRobots();
  //ur_Robot constructor
  ur_Robot(int yCoordinate, int xCoordinate, direction locateKarel, int BeepCnt);
  void print();
  void turnLeft();
  void move();
  int putBeeper();
  int pickBeeper();
  bool turnOff();
  void locateKarel();
  void printWorld();

  //getter methods
  bool getKarelState();
  int getKarelBeeperCount();
  int getKarelStreet();
  int getKarelAvenue();
  std::string getDirectionString();
  karelWorld getKarelAndWorld();
};

#endif