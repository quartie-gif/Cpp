#pragma once 

//INCLUDES
#include <iostream>
#include <vector>
#include <functional>
#include "Argumenty.h"

/**
* @brief Class SekwencjaAlgorytmow that processes Arguments 
*/

class SekwencjaAlgorytmow
{
    public:

    
        //Method that add a new algorithm to the vector
        void add(std::function<Argumenty(const Argumenty&)>);

        //Method that proccess an arguments
        Argumenty procesuj(const Argumenty& args);




    private:
        std::vector<std::function< Argumenty(const Argumenty&)>> _algo;
};
