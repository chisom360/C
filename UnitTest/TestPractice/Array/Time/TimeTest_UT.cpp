#include "gmock/gmock.h"
#include "Time.h"
//#include "Time.cpp"
#include <stdexcept>

using namespace ::testing;

class TimeClass : public Test
{
public:
  Time timeService;
};

TEST_F(TimeClass, validHourValueCheck)
{
  ASSERT_THAT(timeService.setHour(6), Eq(6));
  for (int i = 0; i <= 23; i++)
  {
    timeService.setHour(i);
    EXPECT_EQ(timeService.setHour(i), Eq(i));
  }
}

TEST_F(TimeClass, Invalid_Hour_Positive_Hour_Value)
{

  EXPECT_THROW({
    try
    {
      timeService.setHour(24);
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

TEST_F(TimeClass, Invalid_Hour_Negative_Hour_Value)
{

  EXPECT_THROW({
    try
    {
      timeService.setHour(-1);
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