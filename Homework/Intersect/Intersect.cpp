#include <iostream>
#include "Intersect.h"

Intersection::Intersection(int street, int Avenue)
{
    Intersect_yCoordinate = Avenue;
    Intersect_xCoordinate = street;
}

Intersection::Intersection(int street, int Avenue, int beeperCnt)
{
    Intersect_yCoordinate = Avenue;
    Intersect_xCoordinate = street;
    numOfBeeperOnIntersect = beeperCnt;
}

Intersection::Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection)
{
    Intersect_yCoordinate = Avenue;
    Intersect_xCoordinate = street;
    numOfBeeperOnIntersect = beeperCnt;
    WallPresentOnIntersect[firstDirection] = 1;
}

Intersection::Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection, Wall secondDirection)
{
    Intersect_yCoordinate = Avenue;
    Intersect_xCoordinate = street;
    numOfBeeperOnIntersect = beeperCnt;
    WallPresentOnIntersect[firstDirection] = 1;
    WallPresentOnIntersect[secondDirection] = 1;
}

Intersection::Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection, Wall secondDirection, Wall thirdDirection)
{
    Intersect_yCoordinate = Avenue;
    Intersect_xCoordinate = street;
    numOfBeeperOnIntersect = beeperCnt;
    WallPresentOnIntersect[firstDirection] = 1;
    WallPresentOnIntersect[secondDirection] = 1;
    WallPresentOnIntersect[thirdDirection] = 1;
}

Intersection::Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection, Wall secondDirection, Wall thirdDirection, Wall forthDirection)
{
    Intersect_yCoordinate = Avenue;
    Intersect_xCoordinate = street;
    numOfBeeperOnIntersect = beeperCnt;
    WallPresentOnIntersect[firstDirection] = 1;
    WallPresentOnIntersect[secondDirection] = 1;
    WallPresentOnIntersect[thirdDirection] = 1;
    WallPresentOnIntersect[forthDirection] = 1;
}

int Intersection::putBeeper()
{
    //increments the number of numOfBeeperOnIntersect
    numOfBeeperOnIntersect = numOfBeeperOnIntersect + 1;

    return numOfBeeperOnIntersect;
}

int Intersection::pickBeeper()
{
    if (numOfBeeperOnIntersect > 0)
    {
        numOfBeeperOnIntersect = numOfBeeperOnIntersect - 1;
        return numOfBeeperOnIntersect;
    }
    if (numOfBeeperOnIntersect == 0)
    {
        return numOfBeeperOnIntersect;
    }
    return numOfBeeperOnIntersect;
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

bool Intersection::wallTo(Wall direction)
{
    return WallPresentOnIntersect[direction];
}

void Intersection::print()
{
    std::cout << "Number of Beeper: " << numOfBeeperOnIntersect << std::endl;
    std::cout << "Is beeper present(No = 0, Yes = 1)? " << checkForBeeper() << std::endl;
    std::cout << "X coordinate: " << Intersect_xCoordinate << std::endl;
    std::cout << "Y coordinate: " << Intersect_yCoordinate << std::endl;
    std::cout << "Wall Present Check (N:S:E:W): " << wallTo(North) << ':'
              << wallTo(South) << ':'
              << wallTo(East) << ':'
              << wallTo(West) << '\n'
              << std::endl;
}
