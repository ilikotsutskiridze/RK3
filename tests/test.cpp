// Copyright ilikotsutskiridze 2021
#include "revert_string.hpp"
#include <gtest/gtest.h>


TEST(Convert, TEST)
{
int a=123;
std::string ans = IntToBin(a);

EXPECT_EQ("1111011", ans);
}

