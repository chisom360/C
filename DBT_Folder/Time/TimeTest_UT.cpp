#include "gtest/gtest.h"
#include "Time.h"
#include "Time.cpp"
#include <stdexcept>

using namespace ::testing;

class TimeClass : public Test
{
public:
  Time timeService;
};


TEST_F(TimeClass, validHourValueCheck)
{
  timeService.setHour(6);
  ASSERT_EQ(timeService.getHour(), 6);
}


TEST_F(TimeClass, LoopThroughAllValidHourValueCheck)
{

  for (int i = 0; i <= 23; i++)
  {
    timeService.setHour(i);
    EXPECT_EQ(timeService.getHour(), i);
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

TEST_F(TimeClass, Invalid_Minute_Positive_Hour_Value)
{

  EXPECT_THROW({
    try
    {
      timeService.setMinute(60);
      FAIL() << "minute must be 0-59";
    }
    catch (const std::exception &e)
    {
      EXPECT_STREQ("minute must be 0-59", e.what());
      throw;
    }
  },
               std::exception);
}

TEST_F(TimeClass, Invalid_Minute_Negative_Hour_Value)
{

  EXPECT_THROW({
    try
    {
      timeService.setMinute(-1);
      FAIL() << "minute must be 0-59";
    }
    catch (const std::exception &e)
    {
      EXPECT_STREQ("minute must be 0-59", e.what());
      throw;
    }
  },
               std::exception);
}

TEST_F(TimeClass, validMinuteValueCheck)
{
  timeService.setMinute(45);
  ASSERT_EQ(timeService.getMinute(), 45);
}


TEST_F(TimeClass, LoopThroughAllValidMinuteValueCheck)
{

  for (int i = 0; i <= 59; i++)
  {
    timeService.setMinute(i);
    EXPECT_EQ(timeService.getMinute(), i);
  }
}
