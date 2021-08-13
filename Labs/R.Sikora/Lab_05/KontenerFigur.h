#pragma once 
#include "Figura.h"
#include <vector>
#include <iostream>

class KontenerFigur: public Figura
{
	public:

		void operator += (const Figura *f)
		{
			m_figures.push_back(f);
		}

		void print(std::ostream &out) const
		{
			for(auto *i: m_figures)
			{

				out << *i;
				std::cout << std::endl;
			}
		}

	private:
		std::vector<const Figura *> m_figures;
};

inline std::ostream & operator << (std::ostream & out, const KontenerFigur &other)
{
	other.print(out);
	return out;
}

