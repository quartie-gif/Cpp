#pragma once

#include <iostream>
#include <string>
#include <utility>

struct X
{
    X() = default;

    X(const std::string &s): _s(std::move(s))
    {

    }

    std::string getName()const {return _s ;}

	virtual ~X() 
    {
		std::cout <<"deleting X "<< _s << std::endl;
	}

    std::string _s;
};

struct Y: public X
{
    Y() = default;

    Y(const std::string &s): X(std::move(s))
    {

    }

    virtual ~Y() 
    {
		std::cout <<"deleting Y "<< _s << std::endl;
	}


};

//Streaming     
std::ostream & operator << (std::ostream & out, const X & ob) {
	
	out << ob.getName();
	return out; 
}