#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


class Data
{
public:
	Data(const std::string & day, std::vector<double> vec): m_day(day), m_vec(vec) {}

	void print(std::ostream & o = std::cout) const
	{
		o << "Monday:";
		for(auto &it: m_vec)
		{
			o << std::setw(7) << it;
		}
		o << std::endl;
	}

	inline const std::vector<double> & getVec() const { return m_vec; }

private:
	std::string m_day;
	std::vector<double> m_vec;
};

Sum sumData(const Data & data)
{
	double _sum = 0.;
	for(auto &it: data.getVec())
	{
		_sum += it;
	}
	return Sum(_sum);
}

inline std::ostream & operator << (std::ostream & o, const Data &data)
{
	data.print(o);
	return o;
}