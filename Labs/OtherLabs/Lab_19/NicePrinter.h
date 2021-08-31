#pragma once

#include <iostream>
#include <string>

struct NicePrinter
{
    NicePrinter(int prefix): _prefix(prefix) {}    

    void separator(int num)
    {
        std::cout << "=====-===== " << num << " =====-=====" << std::endl;
    }

    void header(const std::string & s)
    {
        std::cout << "*" << s << std::endl;
    }

    int _prefix=0;
};