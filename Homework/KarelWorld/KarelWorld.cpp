#include <iostream>
#include "KarelWorld.h"
#include "Intersect.h"

karelWorld::karelWorld()
{
    karelIntersection.push_back(Intersection(2, 4));
    karelIntersection.push_back(Intersection(3, 3));
    karelIntersection.push_back(Intersection(3, 4));
    //karelIntersection.push_back(Intersection(3, 4, 3));
    //karelIntersection.push_back(Intersection(3, 4, 3, East));
    //karelIntersection.push_back(Intersection(3, 4, 3, East, West));
    //karelIntersection.push_back(Intersection(3, 4, 3, East, West, South));
    //karelIntersection.push_back(Intersection(3, 4, 3, East, West, South, North));
}
void karelWorld::print()
{
    std::cout << "The world works! " << std::endl;
}