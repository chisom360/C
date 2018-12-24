#include <iostream>
#include "Intersect.h"

Intersection::Intersection(int street, int Avenue)
{
    mAvenue = Avenue;
    mStreet = street;
    if (Avenue == 1)
    {
        WallPresentOnIntersect[South] = 1;
    }
    if (street == 1)
    {
        WallPresentOnIntersect[West] = 1;
    }
}

Intersection::Intersection(int street, int Avenue, int beeperCnt)
{
    mAvenue = Avenue;
    mStreet = street;
    if (Avenue == 1)
    {
        WallPresentOnIntersect[South] = 1;
    }
    if (street == 1)
    {
        WallPresentOnIntersect[West] = 1;
    }
    numOfBeeperOnIntersect = beeperCnt;
}

Intersection::Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection)
{
    mAvenue = Avenue;
    mStreet = street;
    if (Avenue == 1)
    {
        WallPresentOnIntersect[South] = 1;
    }
    if (street == 1)
    {
        WallPresentOnIntersect[West] = 1;
    }
    numOfBeeperOnIntersect = beeperCnt;
    WallPresentOnIntersect[firstDirection] = 1;
}

Intersection::Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection, Wall secondDirection)
{
    mAvenue = Avenue;
    mStreet = street;
    if (Avenue == 1)
    {
        WallPresentOnIntersect[South] = 1;
    }
    if (street == 1)
    {
        WallPresentOnIntersect[West] = 1;
    }
    numOfBeeperOnIntersect = beeperCnt;
    WallPresentOnIntersect[firstDirection] = 1;
    WallPresentOnIntersect[secondDirection] = 1;
}

Intersection::Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection, Wall secondDirection, Wall thirdDirection)
{
    mAvenue = Avenue;
    mStreet = street;
    if (Avenue == 1) //checks to see if intersect is next to south and west wall boundaries
    {
        WallPresentOnIntersect[South] = 1;
    }
    if (street == 1)
    {
        WallPresentOnIntersect[West] = 1;
    }
    numOfBeeperOnIntersect = beeperCnt;
    WallPresentOnIntersect[firstDirection] = 1;
    WallPresentOnIntersect[secondDirection] = 1;
    WallPresentOnIntersect[thirdDirection] = 1;
}

Intersection::Intersection(int street, int Avenue, int beeperCnt, Wall firstDirection, Wall secondDirection, Wall thirdDirection, Wall forthDirection)
{
    mAvenue = Avenue;
    mStreet = street;
    if (Avenue == 1)
    {
        WallPresentOnIntersect[South] = 1;
    }
    if (street == 1)
    {
        WallPresentOnIntersect[West] = 1;
    }
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
    if (checkForBeeper() == true)
    {
        numOfBeeperOnIntersect = numOfBeeperOnIntersect - 1;
        return numOfBeeperOnIntersect;
    }
    if (checkForBeeper() == false)
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

//returns beepercount
int Intersection::getbeeperCount()
{
    return numOfBeeperOnIntersect;
}

//returns Avenue
int Intersection::getAvenue()
{
    return mAvenue;
}

// returns street
int Intersection::getStreet()
{
    return mStreet;
}