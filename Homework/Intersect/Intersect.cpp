#include <iostream>
#include "Intersect.h"

Intersection::Intersection(int &x, int &y, bool Beeper, Wall &direction)
    : Intersect_xCoordinate(x), Intersect_yCoordinate(y), beeperPresent(false), facingDirection(direction)
{
}

Intersection::Intersection()
    : Intersect_xCoordinate(1), Intersect_yCoordinate(23), facingDirection(East)
{
}
bool Intersection::checkForBeeper()
{
    if ((beeperPresent == false) && (numOfBeeperOnIntersect == 0))
    {
        return false;
    }
    else if ((beeperPresent == true) || (numOfBeeperOnIntersect > 0))
    {
        return true;
    }

    return beeperPresent;
}

// check to see if intersect is next to West wall
bool Intersection::IntersectNextToWestWall()
{
    if (Intersect_xCoordinate == 1)
    {
        wallPresent = true;
        return true;
    }
    else if (Intersect_xCoordinate > 1)
    {
        return false;
    }
    return 0;
}

// Check to see if intersect is next to south wall
bool Intersection::IntersectNextToSouthWall()
{
    if (Intersect_yCoordinate == 1)
    {
        wallPresent = true;
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
    intersectInfo();
    std::cout << "Is beeper present(No = 0, Yes = 1)? " << checkForBeeper() << std::endl;
    std::cout << "X coordinate: " << Intersect_xCoordinate << std::endl;
    std::cout << "Y coordinate: " << Intersect_yCoordinate << std::endl;
    std::cout << "Facing Direction: " << facingDirection << std::endl;
    //std::cout << "direction: " << setDirection << std::endl;
    std::cout << "West wall check: " << IntersectNextToWestWall() << std::endl;
}

// this function checks to see what is on the intersect
Intersection Intersection::intersectInfo()
{
    if ((WallPresentOnIntersect[North]) == 1)
    {
        std::cout << "There is a North facing wall" << std::endl;
        //setDirection = "North";
        wallPresent = true;
    }
    if ((WallPresentOnIntersect[South]) == 1 || (IntersectNextToSouthWall() == true))
    {
        std::cout << "There is a South facing wall" << std::endl;
        //setDirection = "South";
        wallPresent = true;
    }
    if (WallPresentOnIntersect[East] == 1)
    {
        std::cout << "There is a East facing wall" << std::endl;
        //setDirection = "East";
        wallPresent = true;
    }
    if ((WallPresentOnIntersect[West]) == 1 || (IntersectNextToWestWall() == true))
    {
        std::cout << "There is a West facing wall" << std::endl;
        //setDirection = "West";
        wallPresent = true;
    }

    return Intersection(Intersect_xCoordinate, Intersect_yCoordinate, beeperPresent, facingDirection);
}
