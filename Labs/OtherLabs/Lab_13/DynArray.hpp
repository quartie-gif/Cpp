#pragma once

#include <iostream>
#include <string>
#include <cstring>


template<typename T>
class DynArray
{
public:

	DynArray(unsigned size): _size(size)
	{
		_arr = new T[size];
	}

	DynArray(unsigned size, const T* arr): _size(size)
	{
		// if(_arr != nullptr)
		// 	delete [] _arr;

		_arr = new T[size];

		for(unsigned i=0; i<size; ++i)
			_arr[i] = arr[i];
	}

	~DynArray() 
	{ 
		delete []  _arr; 
	} 

	unsigned size() const
	{
		return _size;
	}

	T& operator [] (unsigned index)
	{
		return _arr[index];
	}

	T& operator [] (unsigned index) const
	{
		return _arr[index];
	}

	void append(const std::string &str)
	{
		strcpy(*this, str);
	}

	class Iterator
	{
	public:

		Iterator(T* ptr): _ptr(ptr) {}

		void operator ++(){
			++_ptr;
		}
		
		bool operator != (const Iterator &it)
		{
			return _ptr != it._ptr;
		}

		T& operator *() 
		{
			return *_ptr;
		}

		T* operator ->() 
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};

	Iterator begin()
	{
		return Iterator(_arr);
	}

	Iterator end()
	{
		return Iterator(_arr+_size);
	}

private:
	unsigned _size = 0;
	T* _arr;
};

template<typename T>
std::ostream & operator << (std::ostream &o, const DynArray<T> &array)
{
	o << "{\"" << array[0] << "\"";
	for(unsigned i=1; i<array.size(); ++i)
	{
		o << ",\"" << array[i] << "\"";
	}
	o << "}";
	return o;
}