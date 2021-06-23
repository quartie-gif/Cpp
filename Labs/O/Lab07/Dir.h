#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include "File.h"
#include "SoftLink.h"
#include <memory>

class Dir final : public File
{
public:
	Dir(const std::string &name):File(m_name), m_name(name) {}

	~Dir() 
	{
		std::cout << "Destruktor Dir";
		for(auto &el: m_vec)
		{
			
		}	

	}

	void operator += (File* dir)
	{
		m_vec.push_back(dir);
	}

	void print(std::ostream &o, const int level) const override 
	{
		for(unsigned i=0; i<level; ++i)
		{
			o << "  ";
		}

		o << getName() << " (dir)"<< std::endl;

		for(auto &el: m_vec)
		{
			el->print(o, level + 1);
		}	
			
	}

	File *getDir(const std::string &name) override
	{
		for(auto &el: m_vec)
		{
			if(name == m_name) return el;
		}
		for(auto &el: m_vec)
		{
			if(el->get(name))
			{
				return el->get(name);
			}
		}
		return nullptr;

	}

	const std::string &getName() const override { return m_name; } 

protected:
	std::string m_name;
	std::vector<File* > m_vec;
};

inline std::ostream & operator << (std::ostream &o, const Dir & other)
{
	other.print(o, 0);
	return o;
}