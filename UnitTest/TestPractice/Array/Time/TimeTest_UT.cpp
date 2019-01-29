#include "gmock/gmock.h"
#include "Time.h"

using namespace ::testing;

class TimeClass: public Test {
public:
   Time time;
};

TEST_F(TimeClass, IsEmptyWhenCreated) {
   
}


