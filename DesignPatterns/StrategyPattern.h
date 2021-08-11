#pragma once

#include <iostream> 
#include <string> 

class Strategy
{
    public:
        virtual ~Strategy() {}

        virtual std::string DoSomething() const = 0;
};

class Duck
{
    public:

        Duck(Strategy *strategy = nullptr): _strategy(strategy)
         {}

        ~Duck() 
        { 
            delete _strategy; 
        }

        void setStrategy(Strategy *strategy)
        {
            delete _strategy;
            this -> _strategy = strategy;
        }

        void DoSomeBusinessLogic() const
        {
            std::cout << "New behaviour : ";
            std::string result = this->_strategy->DoSomething();
            std::cout << result << "\n";
        }
    private:
        Strategy *_strategy;
};

class IQuackBehaviour: public Strategy
{
    public:
       std::string DoSomething() const override 
       {
           return  "Quacking";
       }

    private:

};

class IFlyBehaviour: public Strategy
{
    public:
       std::string DoSomething() const override 
       {
           return "Flying";
       }

    private:

};


inline void ClientCodeStrategy()
{
    Duck *duck = new Duck(new IQuackBehaviour);
    std::cout << "Duck is\n";
    duck->DoSomeBusinessLogic();
    std::cout << "\n";
    std::cout << "Duck is\n";
    duck->setStrategy(new IFlyBehaviour);
    duck->DoSomeBusinessLogic();
    delete duck;
}