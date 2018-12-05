#include <iostream>
#include "KarelWorld.h"
#include "Intersect.h"

karelWorld::karelWorld()
{
    karelIntersection.push_back(Intersection(2, 4));
    karelIntersection.push_back(Intersection(3, 3));
    karelIntersection.push_back(Intersection(3, 4));
}
void karelWorld::print()
{
    std::cout << "The world works! ";
}