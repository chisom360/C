#include <iostream>
#include "KarelWorld.h"
#include "Intersect.h"
#include <algorithm>

karelWorld::karelWorld()
{

    karelIntersection.push_back(Intersection(2, 4));
    karelIntersection.push_back(Intersection(1, 6, 3));
    karelIntersection.push_back(Intersection(4, 3, 34, East));
    karelIntersection.push_back(Intersection(5, 7, 3, East, West));
    karelIntersection.push_back(Intersection(13, 44, 3, East, West, South));
    karelIntersection.push_back(Intersection(32, 64, 67, East, West, South, North));
}

int karelWorld::getBeeperCount(int street, int avenue)
{
}

/*
int karelWorld::incrementBeeperCount(int street, int avenue)
{
}

int karelWorld::decrementBeeperCount(int street, int avenue)
{
}

int karelWorld::hasCorner(int street, int avenue)
{
}

bool karelWorld::wallToNorth(int street, int avenue)
{
}


*/
void karelWorld::print()
{

    std::cout << "karelIntersection contains:";
    for (unsigned i = 0; i < karelIntersection.size(); i++)
        std::cout << karelIntersection[i].getbeeperCount();
    std::cout << '\n';
    std::cout << "The world works! " << std::endl;
}