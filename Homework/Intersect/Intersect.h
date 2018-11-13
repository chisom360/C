#ifndef Intersect_H
#define Intersect_H

/*
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

const int arraySize = 4; // WallPresentOnIntersect arraysize

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
    Wall facingDirection;

    // initialize the WallPresentOnIntersect with zero (false)
    // WallPresentOnIntersect[0] North wall,
    // WallPresentOnIntersect[1] South wall,
    // WallPresentOnIntersect[2] East wall,
    // WallPresentOnIntersect[3] West wall
    bool WallPresentOnIntersect[arraySize] = {0, 0, 0, 1}; // for debug
    // bool WallPresentOnIntersect[arraySize] = {false};
    int Intersect_xCoordinate;
    int Intersect_yCoordinate;
    bool beeperPresent = false;
    bool wallPresent = false;
    int numOfBeeperOnIntersect = 1;
    // std::string setDirection = " ";

  public:
    Intersection(); // constructor with no arg
    Intersection intersectInfo();
    Intersection(int &x, int &y, bool Beeper, Wall &direction); // constructor with arg
    void print();
    bool checkForBeeper();
    bool IntersectNextToSouthWall();
    bool IntersectNextToWestWall();
};
#endif