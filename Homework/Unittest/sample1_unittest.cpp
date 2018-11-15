#include <iostream>
#include <gtest/gtest.h>

using namespace std;

TEST(TestName, Subtest_1)
{
    ASSERT_TRUE(1 == 1);
    //cout << "After assertion " << endl;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//g++ sample1_unittest.cpp -lgtest -lgtest_main -pthread