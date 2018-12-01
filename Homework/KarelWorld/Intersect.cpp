#include <iostream>
#include "Intersect.h"

Intersection::Intersection()
    : Intersect_xCoordinate(1), Intersect_yCoordinate(23)
{
}

// check for beeper on an intersect
bool Intersection::checkForBeeper()
{
    if (numOfBeeperOnIntersect == 0)
    {
        return beeperPresent = false;
    }
    else if (numOfBeeperOnIntersect > 0)
    {
        return beeperPresent = true;
    }
    return beeperPresent;
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
    std::cout << "West wall check: " << IntersectNextToWestWall() << std::endl;
    std::cout << "North wall check: " << northFacingWall() << std::endl;
    std::cout << "south wall check: " << southFacingWall() << std::endl;
    std::cout << "East wall check: " << eastFacingWall() << std::endl;
    std::cout << "West wall check: " << westFacingWall() << std::endl;
}

// check for north facing wall on intersect
bool Intersection::northFacingWall()
{
    if (WallPresentOnIntersect[North] == 1)
    {
        std::cout << "There is a North facing wall" << std::endl;
        return true;
    }
    else if (WallPresentOnIntersect[North] == 0)
    {
        return false;
    }
    return WallPresentOnIntersect[North];
}

// check for south facing wall on intersect
bool Intersection::southFacingWall()
{
    if (WallPresentOnIntersect[South] == 1 || IntersectNextToSouthWall() == true)
    {
        std::cout << "There is a South facing wall" << std::endl;
        return true;
    }
    else if (WallPresentOnIntersect[South] != 1 || IntersectNextToSouthWall() == false)
    {
        return false;
    }
    return WallPresentOnIntersect[South];
}

// check for east facing wall on intersect
bool Intersection::eastFacingWall()
{
    if (WallPresentOnIntersect[East] == 1)
    {
        std::cout << "There is a East facing wall" << std::endl;
        return true;
    }
    else if (WallPresentOnIntersect[East] != 1)
    {
        return false;
    }
    return WallPresentOnIntersect[East];
}

// check for west facing wall on intersect
bool Intersection::westFacingWall()
{
    if (WallPresentOnIntersect[West] == 1 || IntersectNextToWestWall() == true)
    {
        std::cout << "There is a West facing wall" << std::endl;
        return true;
    }
    else if (WallPresentOnIntersect[West] != 1 || IntersectNextToWestWall() == false)
    {
        return false;
    }
    return WallPresentOnIntersect[West];
}