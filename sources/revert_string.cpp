// Copyright ilikotsutskiridze 2021
#include <revert_string.hpp>


void revert_string(const std::string& input_str, std::ofstream& output_str)
{
    std::string tmp_str = input_str;

    std::reverse(tmp_str.begin(), tmp_str.end());

    output_str << tmp_str;
}

