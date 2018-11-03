#include <iostream>
#include <string>

enum direction
{
  East = 1,
  North = 2,
  West = 3,
  South = 4
};

class ur_Robot
{
private:
  int x, y, beeperCount;
  bool karelState = true;
  direction locateRobot;
  std::string setDirection = " ";

public:
  //ur_Robot constructor
  ur_Robot(int xCoordinate, int yCoordinate, direction locateKarel, int BeepCnt);
  friend std::ostream &operator<<(std::ostream &os, const ur_Robot &r);
  void print();
  void turnLeft();
  int putBeeper();
  int pickBeeper();
  void move();
  bool turnOff();
  void locateKarel();
  void setX(int new_x);
  void setY(int new_y);
  int GetXCoordinate() const;
  int GetYCoordinate() const;
  ~ur_Robot(); //destructor
};
ur_Robot::~ur_Robot() {}

void ur_Robot::move()
{
  if (locateRobot == East)
  {
    x += 1;
  }

  else if (locateRobot == South)
  {
    locateRobot = East;
  }
  else if (locateRobot == West)
  {
    y += 1;
  }
  else if (locateRobot == North)
  {
    locateRobot = West;
  }
}

void ur_Robot::turnLeft()
{

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

std::ostream &operator<<(std::ostream &os, const ur_Robot &r)
{
  os << "( " << r.x << "," << r.y << ","
     << r.setDirection << "," << r.beeperCount
     << "," << (r.karelState ? "On" : "Off") << ")";
  return os;
}

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
//PickBeeper function increments the number of beeper
int ur_Robot::pickBeeper()
{
  return beeperCount += 1;
}

//this function checks to see if there is any more beepers left in the beeper bag
// if there are, it puts beeper and decrements beeper count but if there is none
// it prints a message and returns beeperCount
int ur_Robot::putBeeper()
{
  if (beeperCount >= 1)
  {
    return beeperCount -= 1;
  }
  else
  {
    return beeperCount;
  }
}

ur_Robot::ur_Robot(int xCoordinate, int yCoordinate, direction locateKarel, int BeepCnt)
{
  x = xCoordinate;
  y = yCoordinate;
  beeperCount = BeepCnt;
  locateRobot = locateKarel;
}

int ur_Robot::GetXCoordinate() const
{
  return x;
}

void ur_Robot::setX(int new_x)
{
  x = new_x;
}

void ur_Robot::setY(int new_y)
{
  y = new_y;
}

int ur_Robot::GetYCoordinate() const
{
  return y;
}

int main()
{
  ur_Robot karel(1, 1, North, 10);
  //karel.turnOff();
  //karel.putBeeper();
  //karel.pickBeeper();
  //karel.locateKarel();
  karel.print();
  karel.turnLeft();
  karel.print();
  karel.turnLeft();
  karel.print();
  karel.turnLeft();

  return 0;
}
