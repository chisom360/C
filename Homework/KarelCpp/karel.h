#include <iostream>
#include <string>

#ifndef KAREL_H
#define KAREL_H

enum direction
{
  East = 1,
  North = 2,
  West = 3,
  South = 4
};

class ur_Robot
{
private:
  int westWall = 1;
  int southWall = 1;
  int x, y, beeperCount;
  bool karelState = true;
  direction locateRobot;
  std::string setDirection = " ";

public:
  //ur_Robot constructor
  ur_Robot(int xCoordinate, int yCoordinate, direction locateKarel, int BeepCnt);
  friend std::ostream &operator<<(std::ostream &os, const ur_Robot &r);
  void print();
  void turnLeft();
  void move();
  int putBeeper();
  int pickBeeper();
  bool turnOff();
  void locateKarel();
};

#endif