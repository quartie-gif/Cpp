#include <iostream> 
#include <string> 
#include "main.h"



int main(int argc, char const *argv[])
{
    {
        std::cout << "------------------------ Singelton ------------------------" << std::endl;

        Singleton<int>::instance().setFirstParameter(12);
        Singleton<int>::instance().setSecondParameter(3);


        std::cout << "First parameter was set to:\t" << Singleton<int>::instance().getFirstParameter() << std::endl;

        std::cout << "Second parameter was set to:\t" << Singleton<int>::instance().getSecondParameter() << std::endl;


    }


    {
        /**
        * The client code supports all classes that follow the Target interface.
        */
        std::cout << "------------------------ ADAPTER ------------------------" << std::endl;

        std::cout << "Client: I can work just fine with the Target objects:\n";
        Target *target = new Target;
        ClientCode(target);
        std::cout << std::endl;
        ThingToAdapt *thing = new ThingToAdapt;
        std::cout << "Client: The thing class has a weird interface. See, I don't understand it:\n";
        std::cout << "thing: " << thing->SpecificRequest();
        std::cout << std::endl;
        std::cout << "Client: But I can work with it via the Adapter:\n";
        Adapter<ThingToAdapt*> *adapter = new Adapter<ThingToAdapt*>(thing);
        ClientCode(adapter);
        std::cout << std::endl;

        delete target;
        delete thing ;
        delete adapter;

    }

    return 0;
}
