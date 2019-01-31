#include "gmock/gmock.h"
#include "Time.h"
#include "Time.cpp"
#include <stdexcept>

using namespace ::testing;

class TimeClass : public Test
{
public:
  Time time;
};

//THis checks for Positive invalid hour
TEST_F(TimeClass, Invalid_Hour_Value_Check)
{
  EXPECT_THROW({
    try
    {
      time.setHour(24);
      FAIL() << "hour must be 0-23";
    }
    catch (const std::exception &e)
    {
      EXPECT_STREQ("hour must be 0-23", e.what());
      throw;
    }
  },
               std::exception);
}

//Check for valid hour
TEST_F(TimeClass, valid_Hour_Value_Check)
{
  for (int i = 0; i <= 23; i++)
  {
    time.setHour(i);
    }
}