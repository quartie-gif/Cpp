#pragma once 

//INCLUDES
#include <iostream>

class Argumenty
{
public:
	//Defualt constructor
	Argumenty();

	//Constructor that creates an array of size num
	Argumenty(int num);
	
	//Copy constructor
    Argumenty(const Argumenty & arg);

	//Making class a functor
	Argumenty & operator () (const int index, const double val);

	//Overloaded operator [] for changing
	double & operator [] (const int index);

	//Overloaded operaotr [] for reading
	double & operator [] (const int index) const;

	//Method for printing to std::ostream
	void print(std::ostream & strm = std::cout) const;

	//Getter for size
	int getSize() const;

	//Static function that returns a single argument
    static Argumenty pojedynczy(double x);


protected:	
	double * m_arg; 	//An array o doubles that stores values
	int m_size;			//Size of an array
};

//Overloaded operator << 
inline std::ostream & operator << (std::ostream &out, const Argumenty &args)
{
    args.print(out);
    return out ;
}


