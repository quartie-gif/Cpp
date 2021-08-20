#pragma once

#include <iostream>
#include <string>

class Person
{
    public:
        Person(bool isWoman, const std::string &name):
        _isWoman(isWoman),
        _name(std::move(name))
        {}

        static Person kobieta(const std::string &name)
        {
            return Person(true, std::move(name));
        }
        static Person mezczyzna(const std::string &name)
        {
            return Person(false, std::move(name));
        }

        std::ostream & print(std::ostream & out) const 
        {
            out << _name << " ";
            _isWoman ? out << "K": out << "M";
            return out;
        }

        inline bool isWoman() const { return _isWoman; }
    private:
        bool _isWoman = false;
        std::string _name;
};

std::ostream & operator << (std::ostream & out, const Person & person) 
{
	return person.print(out);
}