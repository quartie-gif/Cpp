#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <numeric>


struct Person
{
    Person(std::string name, std::vector<double> data):
    _name(std::move(name)),
    _vec(data)
    {}

    Person(std::string name, std::initializer_list<double> data):
    _name(std::move(name)),
    _vec(data)
    {}

    void print() const 
    {
        std::cout << this -> _name;
        for_each(_vec.begin(), _vec.end(), [](double x){
            std::cout << "\t" << x;
            });
        std::cout << std::endl;
    }

    double getSum() const
    {
        return std::accumulate(_vec.begin(), _vec.end(), 0.);
    }

    

    const double* notIntScores() const
    {
        for(auto &it: _vec )
        {
            if(it - std::floor(it) != 0 ) return &it;
        }

        return nullptr;
    }
    
    unsigned countGoodScores() const
    {
        return std::count_if(_vec.begin(), _vec.end(), [](const double &val){
            return (val>=3) ? true: false;
        });
    }

    //Firends

    friend double averageScore(const Person& person);

    //Fields
    std::string _name;
    std::vector<double> _vec = {};
};



/*---------------------------- DATA ----------------------------------*/

struct Data
{

    void operator += (const Person &person )
    {
        _arr[_current++] =const_cast<Person *>(&person);
    }

    void operator += (Person &person )
    {
        _arr[_current++] = &person;
    }
    

    void fullprint() const
    {
        std::for_each(_arr.begin(), _arr.end(), [](const Person *person){
            std::cout << " srednia: " << averageScore(*person);
            std::cout << " suma: " << person -> getSum();
            std::cout << " oceny: ";
            person-> print();
        });
    }

    //Fields
    std::array<Person*, 3> _arr;
    int _current = {};
};

double averageScore(const Person& person)
{
    return person.getSum()/person._vec.size();
}

auto badScores = [](auto& x) {if(x <= 2.5) return true; else return false;};




