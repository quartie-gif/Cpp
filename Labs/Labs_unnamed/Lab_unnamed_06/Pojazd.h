#pragma once

#include <iostream>
#include <string>
#include "Predkosc.h"


class Pojazd
{

protected:
	std::string _id;
public:
	virtual ~Pojazd() {}
	Pojazd() {} 
	Pojazd(const std::string& id): _id(id) {}

	virtual void print() const 
	{

	}
};

std::ostream & operator << (std::ostream &o, const Pojazd &object)
{
	o << "";
	return o;
}

struct PojazdLadowy: virtual public Pojazd
{
	PredkoscMaksymalna _vel;

	PojazdLadowy(const std::string& id, PredkoscMaksymalna vel): Pojazd(id), _vel(vel) {}

	int predkoscMaksymalna_Lad() const
	{
		return _vel._vel;
	}
	
};

struct PojazdWodny: virtual public Pojazd
{
	PredkoscMaksymalna _vel;
	PojazdWodny(const std::string& id, PredkoscMaksymalna vel): Pojazd(id), _vel(vel) {}


	int predkoscMaksymalna_Woda() const
	{
		return _vel._vel;
	}


};

struct Samochod: public PojazdLadowy

{

	Samochod(const std::string& id, PredkoscMaksymalna vel): PojazdLadowy(id, vel) {}

	void print() const override
	{
		
	}

	int predkoscMaksymalna() const
	{
		return predkoscMaksymalna_Lad();
	}
};

struct Rower: public PojazdLadowy
{
	Rower(const std::string& id): PojazdLadowy(id, PredkoscMaksymalna()) {}

	void print() const override
	{
		
	}
};

struct Motorowka: public PojazdWodny
{
	Motorowka(const std::string& id, PredkoscMaksymalna vel): PojazdWodny(id, vel) {}

	void print() const override
	{
		
	}

	int predkoscMaksymalna() const
	{
		return predkoscMaksymalna_Woda();
	}
};

struct Amfibia: public PojazdWodny, public PojazdLadowy
{
	Amfibia(const std::string& id, PredkoscMaksymalna velLad, PredkoscMaksymalna velWoda): PojazdWodny(id, velWoda), PojazdLadowy(id, velLad) {}

	void print() const override
	{
		
	}
};
