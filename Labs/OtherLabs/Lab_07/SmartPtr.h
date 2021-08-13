#pragma once

#include <iostream>
#include <string>
#include "TestClass.h"

class SmartPtr
{
public:


	SmartPtr( TestClass *testclass): _ptr(testclass), _counter(new unsigned()) { ++(*_counter); }

	~SmartPtr() { Delete(); }

	unsigned useCount() const 
	{
		return *_counter;
	}

	TestClass * operator -> () const
	{
		return _ptr;
	}

	TestClass & operator * () const
	{
		return *_ptr;
	}

	SmartPtr(const SmartPtr& ptr)
	{
		this->_ptr = ptr._ptr;
		this->_counter = ptr._counter;
		++(*_counter);
	}

	SmartPtr & operator = ( const SmartPtr &ptr)
	{
		Delete();

		if(this!=&ptr)
		{
			if(this->useCount() == 0) 
				_counter = nullptr;

			this->_ptr = ptr._ptr;
			this->_counter = ptr._counter;
			++(*_counter);
		}
		return *this;
	}


private:
	void Delete()
	{
		if(_counter)
		{
			--(*_counter);
			if(!(*_counter)) 
			{
				delete _ptr;
				delete _counter;
			}	
		}
	}

	TestClass* _ptr;
	unsigned* _counter;
};
