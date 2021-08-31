#pragma once 

#include<iostream>
#include<string>

struct Zwierz
{
    virtual ~Zwierz() {}
    Zwierz(const std::string &name): _name(name){}
    virtual std::string imie() const { return _name; }
    virtual void print() const  = 0;

    std::string _name;
};

struct Owca: public Zwierz
{
    ~Owca()
    { 
        std::cout << "Owca " << _name << " wrocila do zagrody" << std::endl; 
    }

    Owca(const std::string& name): Zwierz(std::move(name)) {}
    void opisz() const { std::cout << "Owca " <<_name << " - " << (_cut?" ostrzyzona":"nieostrzyzona") << std::endl;}

    void print() const override
    {
        opisz();
    }

    void ostrzyz() 
    {
        _cut = true; 
    }
    
    bool _cut = false;
};

struct Krowa: public Zwierz
{
    ~Krowa()
    { 
        std::cout << "Krowa " << _name << " wrocila do obory" << std::endl; 
    }

    Krowa(const std::string& name): Zwierz(std::move(name)) {}

    void print() const override
    {
        std::cout << "Krowa " << _name << std::endl;
    }
};

struct Kon: public Zwierz
{
    ~Kon()
    { 
        std::cout << "Kon " << _name << " wrocila do stajni" << std::endl; 
    }
    Kon(const std::string& name): Zwierz(std::move(name)) {}
    void print() const override
    {
        std::cout << "Kon " << _name << std::endl;
    }
};

