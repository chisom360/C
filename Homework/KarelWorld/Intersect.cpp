#include <iostream>
#include "Intersect.h"

Intersection::Intersection(int street, int Avenue)
//    : Intersect_xCoordinate(Avenue), Intersect_yCoordinate(street)
{
    Intersect_xCoordinate = Avenue;
    Intersect_yCoordinate = street;
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