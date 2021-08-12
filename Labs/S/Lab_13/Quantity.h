#pragma once


#include <iostream>
#include <string>
#include <vector>



class QuantityBase
{
public:
	QuantityBase(const std::string &name): m_name(name) {}

	/// Wypisuje informacje o obiekcie na standardowe wyście.
	virtual void Print() const = 0;

	virtual ~QuantityBase() {}

protected:
	std::string m_name;
};

template<typename T>
class Quantity: public QuantityBase
{
public:
	Quantity(const std::string &val_name, T val): QuantityBase(val_name), m_val(val) {}

	virtual void Print() const 
	{
		std::cout << m_name << ": " << m_val << std::endl;
	}

	inline void SetValue(T val) { m_val = val; }

protected:
	T m_val;
};

template<typename T>
class QuantityWithUnits: public Quantity<T>
{
public:
	QuantityWithUnits(const std::string &val_name, T val, const std::string &unit)
	: Quantity<T>(val_name, val),
	m_unit(unit)
	{}

	void Print() const override 
	{
		std::cout << this -> m_name << ": " << this -> m_val << "[" << m_unit << "]" << std::endl;
	}

private:
	std::string m_unit;
};

using QuantityDouble = Quantity<double>;
using QuantityFloat = Quantity<float>;
using QuantityInt = Quantity<int>;
using QuantityChar = Quantity<char>;
using QuantityBool = Quantity<bool>;

class ArrayOfQuantities
{
public:
	ArrayOfQuantities(const unsigned size): m_maxSize(size) {}

	template<typename T>
	Quantity<T>* CreateAndAdd(const std::string &text, T val);

	void Print() const 
	{
		for(auto &it: m_vec)
		{
			it->Print();
		}
	}

private:
	std::vector<QuantityBase *> m_vec;
	unsigned m_maxSize;
};

template<typename T>
Quantity<T>* ArrayOfQuantities::CreateAndAdd(const std::string &text, T val)
{	
	if(m_vec.size() > m_maxSize){ return nullptr; }
	m_vec.push_back(new Quantity<T>(text, val));
	return dynamic_cast<Quantity<T> *>(m_vec.back());
}
