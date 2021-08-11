#include "wire.h"

// Parametrized constructor
QuantumWire::QuantumWire(double len, unsigned numQuantum): 
_len(len), 
_numQuantum(numQuantum) 
{
    _quantums = new bool[numQuantum];
    for(size_t i=0; i<_numQuantum; ++i)
    {
        _quantums[i] = rand() % 2;
    }
}

//Destructor
QuantumWire::~QuantumWire()
{
    _len = 0.;
    _numQuantum = 0;
    delete [] _quantums;
}
    
//Copy constructor
QuantumWire::QuantumWire(const QuantumWire &wire)
{
    _len = wire._len;
    _numQuantum = wire._numQuantum;
    _quantums = new bool[_numQuantum]; 
    for(size_t i=0; i<wire._numQuantum; ++i)
    {
        _quantums[i] = wire._quantums[i];
    }
}

//Move constructor
QuantumWire::QuantumWire(QuantumWire &&wire):
_len(std::exchange(wire._len, 0.)),
_numQuantum(std::exchange(wire._numQuantum, 0)),
_quantums(std::exchange(wire._quantums, nullptr))
{
    
}

//Move assignement operator oveloading
QuantumWire& QuantumWire::operator = (const QuantumWire &wire)
{
    if(&wire != this)
    {
        _len = wire._len;
        _numQuantum = wire._numQuantum;
        _quantums = new bool[_numQuantum]; 
        for(size_t i=0; i<wire._numQuantum; ++i)
        {
            _quantums[i] = wire._quantums[i];
        } 
    }

    return *this;
}

//Copy assignement operator oveloading
QuantumWire& QuantumWire::operator = (QuantumWire &&wire)
{
    if(&wire != this)
    {
        std::exchange(_len, wire._len);
        std::exchange(_numQuantum, wire._numQuantum);
        std::exchange(_quantums, wire._quantums);
    }

    return *this;
}

//Opeartor *= that increase the length x times
QuantumWire QuantumWire::operator *= (double x)
{
    return *this;
}

//Opeartor * that increase the length x times
QuantumWire QuantumWire::operator * (double x)
{
   return (*this *= x);
}

//Operator that negate stats of quantums
QuantumWire QuantumWire::operator ! ()
{
    for(size_t i=0; i<_numQuantum; ++i)
    {
        _quantums[i] = !_quantums[i];
    }
    return *this; 
}

//Operator that display quantum at index
bool& QuantumWire::operator [] (unsigned index)
{
   return _quantums[index]; 
}

//Operator that realize predicate
bool QuantumWire::operator () (const QuantumWire wire)
{
    return true;
}


//Function that print object QuantumWire
void QuantumWire::print(std::ostream& o) const
{
    o << "length: " << _len << ", quanta: ";
    for(size_t i=0; i<_numQuantum; ++i)
    {
        o << _quantums[i] << " ";
    }     
}