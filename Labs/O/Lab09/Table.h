#pragma once

#include <iostream>
#include <vector>
#include "Expense.h"




class Table
{
public:
	void operator += (const Expense& item)
	{
		m_exp.push_back(item);
	}

	void print() const
	{
		for(auto &el: m_exp)
		{
			el.print();
		}
	}

	const Table & sort(const int column)
	{
		if(column)
		{

		}
		return *this;
	}

	const Table & sortByMean()
	{
		return *this;
	}
private:
	std::vector<Expense> m_exp;
};