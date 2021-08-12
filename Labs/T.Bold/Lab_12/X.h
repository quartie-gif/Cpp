#pragma once 

#include <iostream>
#include <string>


class X
{
	public:
		X() = default;
		X(const std::string &name): m_name(name) {};
		virtual ~X() { std::cout << "Deleting X: " << getName() << std::endl; };
		std::string getName() const{return m_name; };

	private:
		std::string m_name;
};

inline std::ostream & operator << (std::ostream &strm, const X &other)
{
	return strm << other.getName();
}


class Y: public X
{
	public:
		Y(const std::string &name): X(name){};
		~Y(){ std::cout << "Deleting Y: " << std::endl; };
		std::string getName() const{return m_name; };

	private:
		std::string m_name;
};

inline std::ostream & operator << (std::ostream &strm, const Y &other)
{
	return strm << other.getName();
}