// Copyright ilikotsutskiridze 2021
#include "revert_string.hpp"
#include <gtest/gtest.h>


TEST(ReverseStr, InFileStream)
{
    std::string InputText = "HelloWorld!";
    std::string FilePath = "Output.txt";
    std::ofstream Out{ FilePath };

    revert_string(InputText, Out);
    Out.close();

    std::string Result;
    std::ifstream in{ FilePath };
    in >> Result;

    EXPECT_EQ(Result, "!dlroWolleH");
}
