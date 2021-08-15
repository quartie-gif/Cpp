#pragma once

#include <iostream>

/***
*   @brief Class that represents an Observator
*/
class Obserwator
{
    public:
        //Virtual method that that is used for updates
        virtual void update(int x) = 0;
};

/***
*   @brief Class that represents an Observator that count a sum of elements being observed
*/
class ObserwatorLicznik: public Obserwator
{
    public:
        //method that that updates _sum
        void update(int x) override 
        {
            _sum += x;
        }

        //Method that returns a sum
        int suma() const 
        {
            return _sum;
        }
        
    private:
        int _sum = 0;   //Sum of elements
};

/***
*   @brief Class that represents an Observator that prints out elements being observed
*/
class ObserwatorWypisywacz: public Obserwator
{
    public:

        //method that that updates printing
        void update(int x) override 
        {
            std::cout << " " << x;
        }
};