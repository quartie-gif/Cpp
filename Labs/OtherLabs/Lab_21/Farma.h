#pragma once 

#include "Zwierz.h"
#include<iostream>
#include<vector>
#include<map>
#include<memory>


struct Farma
{
    Farma() {}
    ~Farma();

    void wypisz(const std::string& text) const
    {
        std::cout << "-- " << text << " --" << std::endl;

        for(auto &it: _animals)
        {
            it->print();
        }
    }

    void dodaj(std::unique_ptr<Zwierz> animal)
    {
        _animals.push_back(std::move(animal));
    }

    int zliczImie(std::string name)
    {
        int counter = 0;
        for(auto &it: _animals)
        {
            if (it->_name == name) ++ counter;
        }
        return counter;
    }

    void statystykaImion() 
    {
        std::map<std::string, int> count;

        for(auto &it: _animals)
        {
            ++count[it->_name];
        }
        
        for (const auto& [key, value] : count) 
        {
            std::cout << key << " = " << value << "; " << std::endl;
        }

    }

    std::vector<Owca *> wyprowadzOwce()
    {
        std::vector<Owca *> sheep;
        for(auto &it:_animals)
        {
            if(dynamic_cast<Owca *>(it.get())) 
            {
                sheep.push_back(dynamic_cast<Owca *>(it.get()));
            }
            
        }
        return sheep;
    }
    
    //Fields
    std::vector<std::unique_ptr<Zwierz>> _animals;    
};