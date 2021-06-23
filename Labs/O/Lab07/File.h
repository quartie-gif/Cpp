#pragma once 

#include <iostream>
#include <string>
#include <vector>


class File
{
public:
	File(const std::string &name, size_t size = 0): m_name(name), m_size(size) {}



	virtual  void print(std::ostream &o, const int level) const 
	{
		for(unsigned i=0; i<level; ++i)
		{
			o << " ";
		}

		o << m_name << " (" << m_size << ")" << std::endl; 
	}

	virtual const std::string &getName() const { return m_name; }

	virtual File *getDir(const std::string &name)
	{
		if(name == m_name) return this;
		return nullptr;
	}

	File *get(const std::string &name)
	{
		if(name == m_name) return this;
		return nullptr;
	}

	virtual File copy(const File* fileToCopy)
	{
		return *fileToCopy;
	}


protected:
	std::string m_name;
	size_t m_size;
};



inline std::ostream & operator << (std::ostream &o, const File & other)
{
	other.print(o, 0);
	return o;
}