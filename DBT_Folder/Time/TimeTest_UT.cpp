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

//Check for a specific valid hour value
TEST_F(TimeClass, validHourValueCheck)
{
  timeService.setHour(6);
  ASSERT_EQ(timeService.getHour(), 6);
}

//Check for valid hour bounds
TEST_F(TimeClass, LoopThroughAllValidHourValueCheck)
{

  for (int i = 0; i <= 23; i++)
  {
    timeService.setHour(i);
    EXPECT_EQ(timeService.getHour(), i);
  }
}

//Check for invalid  positive hour bounds
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

//Check for invalid  Negative hour bounds
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

//Check for invalid  positive Minute bounds
TEST_F(TimeClass, Invalid_Minute_Positive_Value)
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

//Check for invalid  Negative hour bounds
TEST_F(TimeClass, Invalid_Minute_Negative_Value)
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

//Check for a  specific valid minute value
TEST_F(TimeClass, validMinuteValueCheck)
{
  timeService.setMinute(45);
  ASSERT_EQ(timeService.getMinute(), 45);
}

//Check for a range of valid minute value
TEST_F(TimeClass, LoopThroughAllValidMinuteValueCheck)
{

  for (int i = 0; i <= 59; i++)
  {
    timeService.setMinute(i);
    EXPECT_EQ(timeService.getMinute(), i);
  }
}

///////////////////////////////////////////////////
//Check for invalid  positive Seconds bounds
TEST_F(TimeClass, Invalid_Second_Positive_Value)
{

  EXPECT_THROW({
    try
    {
      timeService.setSecond(60);
      FAIL() << "second must be 0-59";
    }
    catch (const std::exception &e)
    {
      EXPECT_STREQ("second must be 0-59", e.what());
      throw;
    }
  },
               std::exception);
}

//Check for invalid  Negative seconds bounds
TEST_F(TimeClass, Invalid_Seconds_Negative_Value)
{

  EXPECT_THROW({
    try
    {
      timeService.setSecond(-1);
      FAIL() << "second must be 0-59";
    }
    catch (const std::exception &e)
    {
      EXPECT_STREQ("second must be 0-59", e.what());
      throw;
    }
  },
               std::exception);
}

//Check for a  specific valid seconds value
TEST_F(TimeClass, validSecondsValueCheck)
{
  timeService.setMinute(59);
  ASSERT_EQ(timeService.getMinute(), 59);
}

//Check for a range of valid minute value
TEST_F(TimeClass, LoopThroughAllValidSecondsValueCheck)
{

  for (int i = 0; i <= 59; i++)
  {
    timeService.setSecond(i);
    EXPECT_EQ(timeService.getSecond(), i);
  }
}
