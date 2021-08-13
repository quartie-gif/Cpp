#pragma once

#include "Person.h"
#include <iostream>
#include <string>

class Man: public Person
{
public:
	Man(std::string name):Person(name){}
	Man(std::string name, bool haircut, bool shave): Person(name, haircut, true), _shave(shave) {}


	// funkcje wirtualne 
	void print() const override
	{
		std::cout << name() << (_haircut ? " obciety" : "nieobciety" )<< " i " << (_shave ? "ogolony" : "nieogolony" )<< std::endl; 
	}

    bool done() const override
	{
		return (!_haircut  & _shave);
	} // czy gotowy do opuszczenia zakładu


    void makeup() override
	{

	}// dla kobiet

    void shave() override
	{
		_shave = true;
	} // dla mężczyzn 

	~Man() {std::cout << name() << (_haircut ? " obciety" : "nieobciety" )<< " i " << (_shave ? "ogolony" : "nieogolony" )<< " idzie do domu" << std::endl;}

private:
	bool _shave = false;
};

class Woman: public Person
{
public:

	Woman(std::string name):Person(name,true,false){}
	Woman(std::string name, bool haircut, bool makeup): Person(name, haircut, false), _makeup(makeup) {}
	// funkcje wirtualne 
	void print() const override
	{
		std::cout << name() << (_haircut ?  " obcieta" : " nieobcieta") << " i " << (_makeup ? "umalowana" : "nieumalowana" ) << std::endl; 
	}

    bool done() const override
	{
		return (!_haircut & _makeup);
	} // czy gotowy do opuszczenia zakładu


    void makeup() override
	{
		_makeup = true;
	}// dla kobiet

    void shave() override
	{
		
	} // dla mężczyzn 

	~Woman() {std::cout << name() << (_haircut ?  " obcieta" : " nieobcieta") << " i " << (_makeup ? "umalowana" : "nieumalowana" ) << " idzie do domu" << std::endl;}

private:
	bool _makeup;
};