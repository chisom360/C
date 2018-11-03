#include <iostream>
#include "karel.h"

//move function definition
//Checks to see if karel is off before moving and also checks to see if karel is next
// to south or west wall
void ur_Robot::move()
{
    if (karelState == false)
        return;

    if (locateRobot == East)
    {
        x += 1;
    }

    else if ((locateRobot == South) && (y > southWall))
    {
        y -= 1;
    }
    else if ((locateRobot == West) && (x > westWall))
    {
        x -= 1;
    }
    else if (locateRobot == North)
    {
        y += 1;
    }
}

// Turnleft function definition
void ur_Robot::turnLeft()
{
    if (karelState == false)
        return;
    if (locateRobot == East)
    {
        locateRobot = North;
    }

    else if (locateRobot == South)
    {
        locateRobot = East;
    }
    else if (locateRobot == West)
    {
        locateRobot = South;
    }
    else if (locateRobot == North)
    {
        locateRobot = West;
    }
}

// locatekarel function checks the current enum values and assigns
// coordinate to setDirection string depending on the enum values
void ur_Robot::locateKarel()
{
    if (locateRobot == 1)
    {
        setDirection = "East";
    }
    else if (locateRobot == 2)
    {
        setDirection = "North";
    }
    else if (locateRobot == 3)
    {
        setDirection = "West";
    }
    else if (locateRobot == 4)
    {
        setDirection = "South";
    }
}

//this tells the program how to print the output
std::ostream &operator<<(std::ostream &os, const ur_Robot &r)
{
    os << "( " << r.x << "," << r.y << ","
       << r.setDirection << "," << r.beeperCount
       << "," << (r.karelState ? "On" : "Off") << ")";
    return os;
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
    std::cout << *this << std::endl;
}
//PickBeeper function increments the number of beeper as long as the karel is ON
int ur_Robot::pickBeeper()
{
    if (karelState == true)
    {
        return beeperCount += 1;
    }
    else
    {
        return beeperCount;
    }
}
//this function checks to see if there is any more beepers left in the beeper bag and if karel is On
// before putting down beepers
int ur_Robot::putBeeper()
{
    if ((beeperCount >= 1) && (karelState == true))
    {
        return beeperCount -= 1;
    }
    else
    {
        return beeperCount;
    }
}

// constructor definition
ur_Robot::ur_Robot(int xCoordinate, int yCoordinate, direction locateKarel, int BeepCnt)
{
    x = xCoordinate;
    y = yCoordinate;
    beeperCount = BeepCnt;
    locateRobot = locateKarel;
}
