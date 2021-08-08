#pragma once

#include <string>


/**
 * The Target defines the interface used by the client code.
 */

class Target 
{
    public:
        virtual ~Target() = default;

        virtual std::string Request() const 
        {
            return "Target";
        }
};

/**
 * The ThingToAdapt contains some useful behavior, but its interface is incompatible
 * with the existing client code. The ThingToAdapt needs some adaptation before the
 * client code can use it.
 */

class ThingToAdapt 
{
    public:
    std::string SpecificRequest() const 
    {
        return "!dlroW olleH";
    }
};

template<typename T>
class Adapter: public Target
{
    public:

        //Constructor
        Adapter(const T arg): m_parameter(arg)
        {
            
        }

        //Request that change data and adapt it
        std::string Request() const override
        {
            std::string reverse = m_parameter->SpecificRequest();
            std::reverse(reverse.begin(), reverse.end());
            return "Adapter: " + reverse;
        }
    private:
        T m_parameter;
};

void ClientCode(const Target *target) 
{
    std::cout << target->Request();
}