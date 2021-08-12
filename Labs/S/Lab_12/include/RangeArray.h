#pragma once

#include <iostream>
#include "PairOfNumbers.h"

template<typename T>
class RangeArray
{
public:
	RangeArray(const PairOfNumbers<int, T> &pair): m_size(pair.getSecond() - pair.getFirst())
	{
		m_arr = new T[m_size];
	}

	~RangeArray()
	{
		delete [] m_arr;
	}

	RangeArray(const RangeArray& r): m_size(r.m_size), m_arr(new T[m_size]){
	    for(unsigned i = 0; i < m_size; i++){
	      m_arr[i] = r.m_arr[i];
	    }
	  }

	unsigned Size() const 
	{
		return m_size;
	}

	T &operator [] (int index)
	{
		if ( index<0 )
		{
			return m_arr[m_size + index];
		}
		return m_arr[index];
	}


	T & At(int index) const
	{
		return (*this)[index];
	}


	T &operator [] (int index) const
	{
		if ( index<0 )
		{
			return m_arr[m_size + index];
		}
		return m_arr[index];
	}

private:
	T *m_arr;
	unsigned m_size;
};


