#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(ExampleTests, BasicAssertions) 
{
    std::vector<int> v{1,2,3,4,5};
    ASSERT_EQ(v[0], 1);
}
