#pragma once

#include<iostream>

struct Array
{
    Array(int size): _size(size) {}

    int & operator [] (int index) { return _vec[index]; }

    std::vector<int> _vec;
};