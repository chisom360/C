#ifndef Intersect_H
#define Intersect_H

/**
******************************************************************
* this program keeps track of information in an intersection     *
* 1) Location                                                    *
*   -Street (x coordinate)                                       *
*   -Avenue (y coordinate)                                       *
* 2) Beepers                                                     *
* 3) Walls                                                       *
*    -North, South, East, West                                   *
******************************************************************
*/

/**
 * @param WallPresentOnIntersect arraysize
 */

const int arraySize = 4;

enum Wall
{
  North = 0,
  South,
  East,
  West,
};

class Intersection
{
private:
  /**
   * initialize the WallPresentOnIntersect with zero (false)
   *  @param WallPresentOnIntersect[0] North wall,
   * @param WallPresentOnIntersect[1] South wall,
   * @param WallPresentOnIntersect[2] East wall,
   * @param WallPresentOnIntersect[3] West wall
   */

  bool WallPresentOnIntersect[arraySize] = {0, 0, 0, 0};
  int Intersect_xCoordinate;
  int Intersect_yCoordinate;
  int numOfBeeperOnIntersect = 0;

public:
  void print();
  Intersection(int street, int Avenue);
  Intersection(int street, int Avenue, int beeperCnt);
  Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection);
  Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection, Wall secondDirection);
  Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection, Wall secondDirection, Wall thirdDirection);
  Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection, Wall secondDirection, Wall thirdDirection, Wall forthDirection);

  bool checkForBeeper();
  bool wallTo(Wall dir);
  int putBeeper();
  int pickBeeper();
};
#endif