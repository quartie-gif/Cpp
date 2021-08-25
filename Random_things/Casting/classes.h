#pragma once
#include <iostream>


struct X
{
    
    X() {std::cout << "X constructed!(Base class)" << std::endl;}
    virtual ~X() {std::cout << "X deleted!" << std::endl;}

    virtual void print() const 
    {
        std::cout << "I'm a X class!" << std::endl;
    }

};
struct Y: public X
{
    Y(): X() {std::cout << "Y constructed!" << std::endl;}
    ~Y() {std::cout << "Y deleted!" << std::endl;}

    void print() const override
    {
        std::cout << "I'm a Y class!" << std::endl;
    }



};
struct Z: public X
{
    virtual ~Z() {}

    void print() const override
    {
        std::cout << "I'm a Z class!" << std::endl;
    }
};
