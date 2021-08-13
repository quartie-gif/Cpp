#pragma once

#include <iostream>
#include <vector>
#include "Data.h"
#include <algorithm>
#include <functional>

class Table
{

public:
	Table() = default;

	void operator += (const Data & data)
	{
		m_data.push_back(data);

		//minRow handling
		if(minRow == 0) minRow = data.getVec().size(); 

		else if(data.getVec().size() < minRow) minRow = data.getVec().size();
	}

	void print() const
	{
		for(auto &it: m_data) it.print();
	}
	
	
	const Table& sort(unsigned column)
	{
		if( column > minRow) std::cout << " Indeks " << column << " nieprawidlowy! ";
		else std::sort(m_data.begin(), m_data.end(), [column](const Data& a, const Data& b){return a.getVec()[column] < b.getVec()[column];});
		return *this;
	}

	const Table& sortBy(std::function<bool(const Data&, const Data&)> fun)
	{

		std::sort(m_data.begin(), m_data.end(), fun);
		return *this;
	}

	double minRow = 0;

private:
	std::vector<Data> m_data;
};