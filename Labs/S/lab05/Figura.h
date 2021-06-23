#pragma once

#include<iostream>
#include<string>
#include <vector>
#include "Wierzcholek.h"

class Figura
{
	public:
		Figura() = default;
		
		Figura(const std::string &name): m_name(name)
		{
			std::cout << "Jestem nową figurą "<< name << std::endl;
		}

		Figura & operator += (const Wierzcholek w)
		{
			m_container.push_back(w);
			return *this;
		}

		std::string nazwa() const
		{
			return m_name;
		}

		Figura & dodajW(const Wierzcholek w)
		{
			return *this += w;
		}

		bool operator == (const Figura & f)
		{
			if(this == &f) return true;

			if(m_container.size() != f.m_container.size()) return false;

			for(unsigned i=0; i<m_container.size(); ++i)
			{
				if(m_container[i] != f.m_container[i]) return false;
			}
			return true;
		}

		void print(std::ostream &out) const
		{
			out<< "Figura " << m_name <<": ";
			for(auto &i: m_container)
			{
				out << i;
			}
		}
	protected:
		std::string m_name;
		std::vector<Wierzcholek> m_container;
};


inline std::ostream & operator << (std::ostream & out, const Figura &other)
{
	other.print(out);
	return out;
}
