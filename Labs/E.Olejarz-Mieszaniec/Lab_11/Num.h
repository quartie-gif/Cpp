#pragma once
#include<iostream>
#include<vector>


class num
{
public:
    num(double result) : _result(result)
    {}
    template <typename T>
    static const double srednia(const T * arr, size_t size)
    {
        double sum = 0.;
        for(size_t i = 0; i < size; ++i)
            sum += arr[i];
        return (sum / size);
    }
    template <typename T>
    static const double srednia(const T * arr)
    {
        std::cout << "size" << sizeof(arr)/sizeof(T) << '\n';
        return (srednia(arr, sizeof(arr)/sizeof(arr[0])));
    }
private:
    double _result;
};
