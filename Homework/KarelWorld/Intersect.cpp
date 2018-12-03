#include <iostream>
#include "Intersect.h"

Intersection::Intersection(int street, int Avenue)
    : Intersect_xCoordinate(Avenue), Intersect_yCoordinate(street)
{
}

// check for beeper on an intersect
bool Intersection::checkForBeeper()
{
    if (numOfBeeperOnIntersect == 0)
    {
        return false;
    }
    else if (numOfBeeperOnIntersect > 0)
    {
        return true;
    }
    return numOfBeeperOnIntersect;
}

/**check to see if intersect is next to West wall boundary
 * if intersect is anywere on (1, n) coresponding to (x,y)
 * @param IntersectNextToWestWall() returns true
 * else return false
 */
bool Intersection::IntersectNextToWestWall()
{
    if (Intersect_xCoordinate == 1)
    {
        return true;
    }
    else if (Intersect_xCoordinate > 1)
    {
        return false;
    }
    return 0;
}

/**check to see if intersect is next to West wall boundary
 * if intersect is anywere on (n, 1) coresponding to (x,y)
 * @param IntersectNextToSouthWall() returns true
 * else return false
 */
bool Intersection::IntersectNextToSouthWall()
{
    if (Intersect_yCoordinate == 1)
    {
        return true;
    }
    else if (Intersect_yCoordinate > 1)
    {
        return false;
    }
    return 0;
}

void Intersection::print()
{
    std::cout << "Is beeper present(No = 0, Yes = 1)? " << checkForBeeper() << std::endl;
    std::cout << "X coordinate: " << Intersect_xCoordinate << std::endl;
    std::cout << "Y coordinate: " << Intersect_yCoordinate << std::endl;
    std::cout << "Wall Present Check (N:S:E:W): " << wallTo(North) << ':'
              << wallTo(South) << ':'
              << wallTo(East) << ':'
              << wallTo(West) << std::endl;
}

bool Intersection::wallTo(Wall direction)
{
    return WallPresentOnIntersect[direction];
}