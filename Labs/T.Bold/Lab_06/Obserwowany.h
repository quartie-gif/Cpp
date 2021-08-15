#pragma once

#include <iostream>
#include <vector>
#include "Obserwator.h"

/***
*   @brief Class that objects are being observated
*/
class Obserwowany{
    public:

        //Adding a new observator
        void dodajObserwatora(Obserwator *observator)
        {
            _views.push_back(observator);
        }

        //Updateing info
        void noweDaneNadeszly(int x)
        {
            for (auto it: _views)
            {
                it->update(x);
            }
                
        }

    protected:
        std::vector< Obserwator *> _views; //Vector that stores Observators
};