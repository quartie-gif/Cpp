#pragma once 

#include <iostream>
#include <array>
#include "X.h"

template <int size, typename Type> 

class Array
{
    public:
        Array();
        Type & operator [] (const int index);
        void print(std::ostream & strm) const;

    private:
        std::array<Type, size> m_arr;
};

template <int size, typename Type> 

Type & Array<size, Type>::operator [] (const int index)
{
    return m_arr[index];
}



template <int size, typename Type> 

void Array<size, Type>::print(std::ostream & strm) const
{
    for(const auto& i: m_arr )
    {
        strm << i << " ";
    }
}


template <int size, typename Type> 
Array<size, Type>::Array(): m_arr{Type()} {}


template <> 

std::shared_ptr<X> & Array<5, std::shared_ptr<X> >::operator [] (const int index)
{
    return m_arr[index];
}


template <int size, typename Type> 

inline std::ostream & operator << (std::ostream &strm, const Array<size, Type> &other)
{
	other.print(strm);
	return strm;
}

template <>

void Array<5, std::shared_ptr<X>>::print(std::ostream & strm) const
{
	for(const auto& i: m_arr )
    {
        strm << i << " ";
    }
}


