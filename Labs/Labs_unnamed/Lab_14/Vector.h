#pragma once 

#include <iostream>
#include <functional>
#include <string.h>



template<typename T> 
struct is_pod {
  const static bool pod = false;
};

template<typename T>
class Vect
{
public:

	Vect(unsigned size): _size(size)
	{
		_arr = new T[size];
	}

	~Vect() { delete [] _arr; }

	void buble_sort(std::function<bool(const T&, const T&)> comparsion) 
	{
		unsigned i, j;

		for ( i = 0; i < _size; i++ )
			for (j = i+1; j < _size; ++j ) 
		    	if ( !comparsion(_arr[j], _arr[i]) )
		    	{
		    		swap( _arr[j], _arr[i] );
		    	}
	}

	unsigned size() const { return _size; }

	T& operator [] (unsigned index)
	{
		return _arr[index];
	}

	T& operator [] (unsigned index) const
	{
		return _arr[index];
	}

private:
	unsigned _size = 0;
	T* _arr = nullptr;
};

template<typename T, bool flag>
void swap(T& obj1, T& obj2) {
	T tmp = obj1;
	obj1 = obj2;
	obj2 = tmp;
}
//specjalizacja funkcji swap dla typow pod
template<typename T>
void swap(T& obj1, T& obj2) {
	T* tmp = new T();
	memcpy(tmp, &obj1, sizeof(T));
	memcpy(&obj1, &obj2, sizeof(T));
	memcpy(&obj2, tmp, sizeof(T));
	delete tmp;
}