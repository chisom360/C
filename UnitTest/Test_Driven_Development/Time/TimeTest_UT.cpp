#include "gmock/gmock.h"
#include "Time.h"
#include "Time.cpp"
#include <stdexcept>

using namespace ::testing;

class TimeClass : public Test
{
public:
  Time timeService;
};

/*
//Check for valid hour
TEST_F(TimeClass, valid_Hour_Value_Check)
{
  ASSERT_THAT(timeService.setMinute(5), Eq(5));
  /*int i = 0;
  for (i; i <= 23; i++)
  {
    time.setHour(i);
    ASSERT_THAT(time.setHour(i), Eq(i));
  }
  */
}
* /

    /*
//This checks for Positive invalid hour
TEST_F(TimeClass, Invalid_Hour_Value_Check)
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
*/