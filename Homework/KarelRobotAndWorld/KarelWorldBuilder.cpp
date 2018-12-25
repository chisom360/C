#ifndef KarelWorldBuilder_H
#define KarelWorldBuilder_H
#include <vector>
#include "Intersect.h"
#include "KarelWorldBuilder.h"

std::vector<Intersection> KarelWorldBuilder()
{
    static std::vector<Intersection> world;

    world.push_back(Intersection(2, 6, 3));
    world.push_back(Intersection(1, 6, 3));
    world.push_back(Intersection(4, 3, 34, East));
    world.push_back(Intersection(5, 7, 3, East, West));
    world.push_back(Intersection(13, 44, 3, East, West, South));
    world.push_back(Intersection(32, 64, 67, East, West, South, North));

    return world;
}

#endif