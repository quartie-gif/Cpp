#pragma once 

#include <iostream>

struct Factory
{

	template<typename T>
	T base(const T &num, bool flag = true) const;

	template<typename T>
	T remember_base(const T &num, bool flag) const;

	template<typename T>
	T product() const;
};



template<typename T>
T Factory::base(const T &num, bool flag) const
{
	return remember_base(num, flag);
}

template<typename T>
T Factory::remember_base(const T &num, bool flag) const
{
	static T base = num;

	if(flag == true)
	{
		base = num;
	}

	return base;
}

template<typename T>
T Factory::product() const
{
	return base(T(), false);
}


