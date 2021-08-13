#pragma once

#include <iostream>
#include <vector>
#include <functional>


class FilterCriteria
{
public:
	void add(std::function<bool(int x)> criteria)
	{
		m_criteria.push_back(criteria);
	}

	std::function<bool(int x)> get(int index) const
	{
		return m_criteria[index];
	}

	unsigned int size() const
	{
		return m_criteria.size();
	}

private:
	std::vector<std::function<bool(int x)>> m_criteria;
};
