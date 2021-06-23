#pragma once


#include <iostream>
#include <memory>
#include <vector>
#include <functional>

template <typename T>
struct is_pod
{
	const static bool value = false;
};


template<typename T>
class Vect
{

public:
	Vect(const unsigned int size);
	~Vect();
	T & operator [] (unsigned int index) {return m_arr[index];}
	const T & operator [] (unsigned int index) const {return m_arr[index];}
	const unsigned int & size() const {return m_size;}

	void buble_sort(std::function<bool(const T& a, const T& b)> fun_compare);

	void swap(T & a, T & b);

private:
	T *m_arr;
	unsigned int m_size;
};

template <typename T>
Vect<T>::Vect(const unsigned int size) : m_size(size)
{
	m_arr = new T [size];
}

template <typename T>
Vect<T>::~Vect()
{
	delete [] m_arr;
}

template <typename T>
void Vect<T>::buble_sort(std::function<bool(const T& a, const T& b)> fun_compare)
{
	for(size_t i = 0; i < m_size; ++i)
	{
		for(size_t j = i + 1; j < m_size; ++j)
		{
			if(fun_compare(m_arr[i], m_arr[j]))
				swap(m_arr[i], m_arr[j]);
		}
	}
}

///////////////////////////////////////////////////////////////



template <typename T2>
struct SwapHelper<T2, true>
{
	static void swap(T2 & a, T2 & b)
	{
		T2 temp;
		memcpy(&temp, &a, sizeof(T2));
		memcpy(&a, &b, sizeof(T2));
		memcpy(&b, &temp, sizeof(T2));
	}
};

template <typename T2>
struct SwapHelper<T2, false>
{
	static void swap(T2 & a, T2 & b)
	{
		T2 temp = a;
		a = b;
		b = temp;
	}
};


template <typename T>
void Vect<T>::swap(T & a, T & b)
{
	SwapHelper<T, is_pod<T>::value>::swap(a, b);
}






