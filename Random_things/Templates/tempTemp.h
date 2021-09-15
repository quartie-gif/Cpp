#pragma once

#include <iostream>
#include <utility>

//Wrapper
template<typename T = float>
struct Float_t
{
    Float_t(float val): _val(val) {}

    operator float () const
    {
        return static_cast<float>(_val);
    }

    T _val;
};

using Float = Float_t<float>;


template<typename T>
struct A
{
    using value_type = T;

    A(T val1): 
    _val1(val1)
    {}

    A* operator -> ()
    {
        return this;
    }

    void * operator new(size_t amount)
    {
        std::cout<< "Overloaded new operator " << std::endl;
        void *_arr = malloc(sizeof(T) * amount);
        return _arr;
    }

    void operator delete(void *ptr)
    {
        std::cout<< "Overloaded delete operator " << std::endl;
        free(ptr);
    }

    A& operator + (A & other)
    {
        _val1.first = _val1.first + other._val1.first;
        _val1.second = _val1.second + other._val1.second; 
        return *this;
    }

    void print(std::ostream &out) const
    {
        out << "First: " << _val1.first << "\tSecond: " << _val1.second << std::endl;
    }

    //Fields
    T* _arr;
    T _val1;
};

template<typename T>
std::ostream & operator << (std::ostream &out, const A<T>& other)
{
    other.print(out);
    return out;
}



template<typename T, template<typename  U1 = T, typename U2 = T  > class A>
struct X
{
    X(A<T> temp): _temp(temp)
    {
        std::cout << "X object created!\n";
        std::cout << "First: " << _temp.first << "\tSecond: " << _temp.second << std::endl;
    }

    A<T> _temp;
};


