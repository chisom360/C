#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////////////
/*this program keeps track of information in a corner/intersection
1) Location
    -Street (x coordinate)
    -Avenue (y coordinate)
2) Beepers
3) Walls
    -North, South, East, West
*/
//////////////////////////////////////////////////////////////////////////

const int arraySize = 4; // WallPresentOnIntersect arraysize

enum Wall
{
    North = 0,
    South,
    East,
    West,
};

class Intersection
{
  private:
    Wall facingDirection;

    //initialize the WallPresentOnIntersect with zero (false)
    //WallPresentOnIntersect[0] North wall,
    //WallPresentOnIntersect[1] South wall,
    //WallPresentOnIntersect[2] East wall,
    //WallPresentOnIntersect[3] West wall
    bool WallPresentOnIntersect[arraySize] = {0, 0, 0, 1}; //for debug
                                                           // bool WallPresentOnIntersect[arraySize] = {false};
    int Intersect_xCoordinate;
    int Intersect_yCoordinate;
    bool beeperPresent = false;
    bool wallPresent = false;
    int numOfBeeperOnIntersect = 0;
    //std::string setDirection = " ";

  public:
    Intersection(); // constructor with no arg
    Intersection intersectInfo();
    Intersection(int &x, int &y, bool Beeper, Wall &direction); // constructor with arg
    void print();
    bool checkForBeeper();
    bool IntersectNextToSouthWall();
    bool IntersectNextToWestWall();
};

Intersection::Intersection(int &x, int &y, bool Beeper, Wall &direction)
    : Intersect_xCoordinate(x), Intersect_yCoordinate(y), beeperPresent(false), facingDirection(direction)
{
}

Intersection::Intersection()
    : Intersect_xCoordinate(0), Intersect_yCoordinate(0), facingDirection(East)
{
}
bool Intersection::checkForBeeper()
{
    if ((beeperPresent == false) && (numOfBeeperOnIntersect == 0))
    {
        return false;
    }
    else if ((beeperPresent == true) || (numOfBeeperOnIntersect > 0))
    {
        return true;
    }
    return beeperPresent;
}
// check to see if intersect is next to West wall
bool Intersection::IntersectNextToWestWall()
{
    if (Intersect_xCoordinate == 1)
    {
        wallPresent = true;
        return true;
    }
    else if (Intersect_xCoordinate > 1)
    {
        return false;
    }
    return 0;
}
// Check to see if intersect is next to south wall
bool Intersection::IntersectNextToSouthWall()
{
    if (Intersect_yCoordinate == 1)
    {
        wallPresent = true;
        return true;
    }
    else if (Intersect_yCoordinate > 1)
    {
        return false;
    }
    return 0;
}

void Intersection::print()
{
    intersectInfo();
    std::cout << "Is beeper present(No = 0, Yes = 1)? " << checkForBeeper() << std::endl;
    std::cout << "X coordinate: " << Intersect_xCoordinate << std::endl;
    std::cout << "Y coordinate: " << Intersect_yCoordinate << std::endl;
    std::cout << "Facing Direction: " << facingDirection << std::endl;
    //std::cout << "direction: " << setDirection << std::endl;
    std::cout << "West wall check: " << IntersectNextToWestWall() << std::endl;
}
// this function checks to see what is on the intersect
Intersection Intersection::intersectInfo()
{
    if ((WallPresentOnIntersect[North]) == 1)
    {
        std::cout << "There is a North facing wall" << std::endl;
        //setDirection = "North";
        wallPresent = true;
    }
    if ((WallPresentOnIntersect[South]) == 1 || (IntersectNextToSouthWall() == true))
    {
        std::cout << "There is a South facing wall" << std::endl;
        //setDirection = "South";
        wallPresent = true;
    }
    if (WallPresentOnIntersect[East] == 1)
    {
        std::cout << "There is a East facing wall" << std::endl;
        //setDirection = "East";
        wallPresent = true;
    }
    if ((WallPresentOnIntersect[West]) == 1 || (IntersectNextToWestWall() == true))
    {
        std::cout << "There is a West facing wall" << std::endl;
        //setDirection = "West";
        wallPresent = true;
    }
    return Intersection(Intersect_xCoordinate, Intersect_yCoordinate, beeperPresent, facingDirection);
}

int main()
{
    Intersection intersectClassObject;

    intersectClassObject.print();

    return 0;
}