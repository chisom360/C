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
  direction locateRobot;
  int westWall = 1;
  int southWall = 1;
  int KarelAvenue;
  int KarelStreet;
  int beeperCount = 0;
  bool karelState = true;

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
};

#endif