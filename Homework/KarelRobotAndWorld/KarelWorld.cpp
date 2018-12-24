#include <iostream>
#include "KarelWorld.h"
#include "Intersect.h"
#include <algorithm>
#include <iomanip>
#include <vector>

karelWorld::karelWorld()
{
}

//Note: list is the container that holds the newly created world
karelWorld::karelWorld(std::vector<Intersection> IntersectionList)
{
    list = IntersectionList;
}

// loop through all the available container
// checks to see if that intersection exist, if it does, then return the beeper count on that corner
int karelWorld::getBeeperCount(int street, int avenue)
{
    for (unsigned i = 0; i < list.size(); i++)
    {
        if ((list[i].getStreet() == street) && (list[i].getAvenue()) == avenue)
        {
            return list[i].getbeeperCount();
        }
    }
    return EXIT_SUCCESS;
}

int karelWorld::incrementBeeperCount(int street, int avenue)
{
    for (unsigned i = 0; i < list.size(); i++)
    {
        if ((list[i].getStreet() == street) && (list[i].getAvenue()) == avenue)
        {
            return list[i].putBeeper();
        }
    }
    return EXIT_SUCCESS;
}

int karelWorld::decrementBeeperCount(int street, int avenue)
{
    for (unsigned i = 0; i < list.size(); i++)
    {
        if ((list[i].getStreet() == street) && (list[i].getAvenue()) == avenue)
        {
            return list[i].pickBeeper();
        }
    }
    return EXIT_SUCCESS;
}

// Check to see if a specfic corner is a "non-default" corner
bool karelWorld::hasCorner(int street, int avenue)
{
    for (unsigned i = 0; i < list.size(); i++)
    {
        if ((list[i].getStreet() == street) && (list[i].getAvenue()) == avenue)
        {
            return true;
        }
    }
    return false;
}

//Check for North facing wall in a corner
bool karelWorld::wallToNorth(int street, int avenue)
{
    for (unsigned i = 0; i < list.size(); i++)
    {
        if ((list[i].getStreet() == street) && (list[i].getAvenue()) == avenue)
        {
            return list[i].wallTo(North);
        }
    }
    return EXIT_SUCCESS;
}

//Check for South facing wall in a corner
bool karelWorld::wallToSouth(int street, int avenue)
{
    for (unsigned i = 0; i < list.size(); i++)
    {
        if ((list[i].getStreet() == street) && (list[i].getAvenue()) == avenue)
        {
            return list[i].wallTo(South);
        }
    }
    return EXIT_SUCCESS;
}

//Check for East facing wall in a corner
bool karelWorld::wallToEast(int street, int avenue)
{
    for (unsigned i = 0; i < list.size(); i++)
    {
        if ((list[i].getStreet() == street) && (list[i].getAvenue()) == avenue)
        {
            return list[i].wallTo(East);
        }
    }
    return EXIT_SUCCESS;
}

//Check for West facing wall in a corner
bool karelWorld::wallToWest(int street, int avenue)
{
    for (unsigned i = 0; i < list.size(); i++)
    {
        if ((list[i].getStreet() == street) && (list[i].getAvenue()) == avenue)
        {
            return list[i].wallTo(West);
        }
    }
    return EXIT_SUCCESS;
}

//print information about a  specific street and corner
void karelWorld::print(int street, int avenue)
{
    std::cout << "Container#" << std::setw(5)
              << "Str" << std::setw(5)
              << "Ave" << std::setw(5)
              << "Bper" << std::setw(8)
              << "N_Wall" << std::setw(8)
              << "S_Wall" << std::setw(8)
              << "E_Wall" << std::setw(8)
              << "W_Wall" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    for (unsigned i = 0; i < list.size(); i++)
    {
        if ((list[i].getStreet() == street) && (list[i].getAvenue()) == avenue)
        {
            std::cout << std::setw(4) << i << std::setw(10);
            std::cout << list[i].getStreet() << std::setw(5);

            std::cout << list[i].getAvenue() << std::setw(5);
            std::cout << list[i].getbeeperCount() << std::setw(7);
            std::cout << list[i].wallTo(North) << std::setw(7);
            std::cout << list[i].wallTo(South) << std::setw(8);
            std::cout << list[i].wallTo(East) << std::setw(8);
            std::cout << list[i].wallTo(West);
            std::cout << '\n'
                      << std::endl;
        }
    }
}

// print information about all corners
void karelWorld::print()
{
    std::cout << "Container#" << std::setw(5)
              << "Str" << std::setw(5)
              << "Ave" << std::setw(5)
              << "Bper" << std::setw(8)
              << "N_Wall" << std::setw(8)
              << "S_Wall" << std::setw(8)
              << "E_Wall" << std::setw(8)
              << "W_Wall" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    for (unsigned i = 0; i < list.size(); i++)
    {
        std::cout << std::setw(4) << i << std::setw(10);
        std::cout << list[i].getStreet() << std::setw(5);

        std::cout << list[i].getAvenue() << std::setw(5);
        std::cout << list[i].getbeeperCount() << std::setw(7);
        std::cout << list[i].wallTo(North) << std::setw(7);
        std::cout << list[i].wallTo(South) << std::setw(8);
        std::cout << list[i].wallTo(East) << std::setw(8);
        std::cout << list[i].wallTo(West);
        std::cout << '\n'
                  << std::endl;
    }
}
void karelWorld::print2()
{
    /// print the value of vector
    for (int i = 0; i < list.size(); i++)
        std::cout << list[i].getAvenue();
}