#include <stdexcept>
#include "gtest/gtest.h"

struct foo
{
    int bar(int i)
    {
        if (i > 100)
        {
            throw std::out_of_range("Out of range");
        }
        return i;
    }
};

TEST(foo_test, out_of_range)
{
    foo f;
    try
    {
        f.bar(11);
        FAIL() << "Expected std::out_of_range";
    }
    catch (std::out_of_range const &err)
    {
        EXPECT_EQ(err.what(), std::string("Out of range"));
    }
    catch (...)
    {
        FAIL() << "Expected std::out_of_range";
    }
}