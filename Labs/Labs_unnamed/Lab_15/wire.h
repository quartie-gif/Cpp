#pragma once 

#include <iostream>
#include <string>
#include <utility>
#include <cmath>

//Class that represents QuantumWire
class QuantumWire
{
public:
    // Default constructor
    QuantumWire(): _len(0.), _numQuantum(0), _quantums(nullptr) {}

    // Parametrized constructor
    QuantumWire(double len, unsigned numQuantum);

    //Destructor
    ~QuantumWire();
    
    //Copy constructor
    QuantumWire(const QuantumWire &wire);

    //Move constructor
    QuantumWire(QuantumWire &&wire);

    //Move assignement operator oveloading
    QuantumWire& operator = (const QuantumWire &wire);

    //Copy assignement operator oveloading
    QuantumWire& operator = (QuantumWire &&wire);

    //Opeartor *= that increase the length x times
    QuantumWire operator *= (double x);

    //Opeartor * that increase the length x times
    QuantumWire operator * (double x);

    //Operator that negate stats of quantums
    QuantumWire operator ! ();

    bool operator < (QuantumWire* )
    {
        return true;
    }

    bool operator < (QuantumWire*) const 
    {
        return true;
    }

    //Operator that display quantum at index
    bool& operator [] (unsigned index);

    //Operator that realize predicate
    bool operator () (const QuantumWire wire);

    //Geter for _numQuantum
    unsigned get() const { return _numQuantum;}

    //Function that print object QuantumWire
    void print(std::ostream& o) const;

    //Operator < overloaded;
    bool operator < (const int iter) const
    {
        return iter < get();
    }

    
private:

    //Private members

    double _len;             //length
    unsigned _numQuantum;    //Number of Quantums
    bool* _quantums;         //An array of quantums
};

inline std::ostream & operator << (std::ostream &o, const QuantumWire &wire)
{
    wire.print(o);
    return o;
}

bool operator < (int iter, const QuantumWire& wire)
{
    return iter < wire.get();
}




inline QuantumWire& operator *(double x, QuantumWire wire)
{
    return wire;
}

