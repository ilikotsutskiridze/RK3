// Copyright ilikotsutskiridze 2021
#include <revert_string.hpp>


std::string convert(const int &a)
{
    int bin=0, j;
 
    for(j=0; a>0; j++)
    {
        bin+=(a%2)*pow(10.0,j);
        a/=2;
    }
    
    std::string s=std::to_string(bin);
    return s;
}

