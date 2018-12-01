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
  Wall Direction;
  /**
   * initialize the WallPresentOnIntersect with zero (false)
   *  @param WallPresentOnIntersect[0] North wall,
   * @param WallPresentOnIntersect[1] South wall,
   * @param WallPresentOnIntersect[2] East wall,
   * @param WallPresentOnIntersect[3] West wall
   */

  bool WallPresentOnIntersect[arraySize] = {0, 0, 0, 1};

  // bool WallPresentOnIntersect[arraySize] = {false};
  int Intersect_xCoordinate;
  int Intersect_yCoordinate;
  int numOfBeeperOnIntersect = 1;
  bool beeperPresent = false;

public:
  Intersection(); // constructor with no arg
  Intersection intersectInfo();
  /**
   * constructor with arg
   */
  Intersection(int &x, int &y, bool Beeper, Wall &direction);
  void print();
  bool checkForBeeper();
  bool IntersectNextToSouthWall();
  bool IntersectNextToWestWall();
  bool northFacingWall();
  bool southFacingWall();
  bool eastFacingWall();
  bool westFacingWall();
};
#endif