#include <iostream>
#include "karel.h"

karelWorld ur_Robot::KarelAndWorld; //shared static variable

std::string ur_Robot::getDirectionString()
{
    return setDirectionString;
}

int ur_Robot::getKarelAvenue()
{
    return KarelAvenue;
}

int ur_Robot::getKarelStreet()
{
    return KarelStreet;
}

int ur_Robot::getKarelBeeperCount()
{
    return beeperCount;
}

bool ur_Robot::getKarelState()
{
    return karelState;
}
//move function definition
//Checks to see if karel is off before moving and also checks to see if karel is next
// to south or west wall
void ur_Robot::move()
{
    if (karelState == false)
        return;

    if (locateRobot == east)
    {
        KarelAvenue += 1;
    }

    else if ((locateRobot == south) && (KarelStreet > southWall))
    {
        KarelStreet -= 1;
    }
    else if ((locateRobot == west) && (KarelAvenue > westWall))
    {
        KarelAvenue -= 1;
    }

    else if ((locateRobot == south) && (KarelStreet == southWall))
    {
        karelState = false; //turn off robot if it tries to run into southwall
    }
    else if ((locateRobot == west) && (KarelAvenue == westWall))
    {
        karelState = false; //turn off robot if it tries to run into westwall
    }
    else if (locateRobot == north)
    {
        KarelStreet += 1;
    }
}

// Turnleft function definition
void ur_Robot::turnLeft()
{
    if (karelState == false)
        return;
    if (locateRobot == east)
    {
        locateRobot = north;
    }

    else if (locateRobot == south)
    {
        locateRobot = east;
    }
    else if (locateRobot == west)
    {
        locateRobot = south;
    }
    else if (locateRobot == north)
    {
        locateRobot = west;
    }
}

// locatekarel function checks the current enum values and assigns
// coordinate to setDirectionString string depending on the enum values
void ur_Robot::locateKarel()
{
    if (locateRobot == 1)
    {
        setDirectionString = "east";
    }
    else if (locateRobot == 2)
    {
        setDirectionString = "north";
    }
    else if (locateRobot == 3)
    {
        setDirectionString = "west";
    }
    else if (locateRobot == 4)
    {
        setDirectionString = "south";
    }
}

// turnOff function definition
// This inverts the karelState flag
bool ur_Robot::turnOff()
{
    karelState = false;
    return karelState;
}

void ur_Robot::print()
{
    locateKarel();
    std::cout << "(" << getKarelStreet() << ","
              << getKarelAvenue() << ","
              << getDirectionString() << ","
              << getKarelBeeperCount() << ", "
              << (getKarelState() ? "On" : "Off") << ")" << std::endl;
    getKarelAndWorld();
}
//PickBeeper function increments the number of beeper as long as the karel is ON
int ur_Robot::pickBeeper()
{
    if (karelState == true && beeperCount >= 1)
    {
        return beeperCount += 1;
    }
    else if (beeperCount == 0)
    {
        karelState = false; //turn off robot if karel tries to big beeper and there is no beeper
    }
    return beeperCount;
}
//this function checks to see if there is anKarelStreet more beepers left in the beeper bag and if karel is On
// before putting down beepers
int ur_Robot::putBeeper()
{
    if ((beeperCount >= 1) && (karelState == true))
    {
        return beeperCount -= 1;
    }
    else if (beeperCount == 0)
    {
        //Turn off robot if karel tries to pickup a beeper when beeper count is 0
        karelState = false;
    }
    return beeperCount;
}

// constructor definition
ur_Robot::ur_Robot(int xCoordinate, int yCoordinate, direction locateKarel, int BeepCnt)
    : KarelAvenue(xCoordinate), KarelStreet(yCoordinate), beeperCount(BeepCnt), locateRobot(locateKarel)
{
}
