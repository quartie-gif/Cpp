#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>


//Class that handle errors
struct Calc_error : public std::runtime_error{

	Calc_error(std::runtime_error* err, const std::string &message, const std::string &fileName, const int& line):
	std::runtime_error(*err),
	_err(err),
	_message(message),
	_fileName(fileName),
	_line(line)
	{
		_errors.push_back(this);
	}

	static void handler();

	inline void print() const
	{
		std::cout << "-- z powodu: " << _message << ", " << "[plik = " << _fileName << ", linia = " << _line << "]" << std::endl;
	}

	std::runtime_error* _err; //pointer to error
	std::string _message, _fileName; 
	unsigned _line;
	static std::vector<Calc_error*> _errors; //static vector of Calc_error
};