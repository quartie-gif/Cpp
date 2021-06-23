#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include <string>

class List
{
public:
	List() = default;

	void insert(int element)
	{
		m_list.push_back(element);
	}

	void print(const std::string &text = "") const
	{
		std::cout << text << "[ ";

		for(auto &i: m_list)
		{
			std::cout << i << " ";
		}

		std::cout << "]" << std::endl;
	}

	int & operator [] (unsigned int index)
	{
		return m_list[index];
	}

	const int & operator [] (unsigned int index) const
	{
		return m_list[index];
	}

	List filter(std::function<bool(int x)> filter)
	{

		List listRet;

		for(auto &i: m_list)
		{
			if(filter(i))
			{
				listRet.insert(i);
			}
		}
		return listRet;
	}

private:
	std::vector<int> m_list;
};