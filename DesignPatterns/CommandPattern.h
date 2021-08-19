#pragma once 

#include <iostream>
#include <string>

class Command
{
    public:
        virtual ~Command() {}
        virtual void exec() const = 0;
};

class SimpleCommand: public Command
{
    private:
        std::string _s;

    public:
        SimpleCommand(const std::string s): _s(std::move(s)) {}
        void exec() const
        {
            std::cout << "Simple Command: " << _s << std::endl;
        }
};

class Receiver {
    public:
        void DoSomething(const std::string &a) 
        {
            std::cout << "Receiver: Working on (" << a << ".)\n";
        }
        void DoSomethingElse(const std::string &b) 
        {
        std::cout << "Receiver: Also working on (" << b << ".)\n";
        }
};

class ComplexCommand : public Command {

    private:
        Receiver *_receiver;

        std::string _a;
        std::string _b;

    public:
        ComplexCommand(Receiver *receiver, const std::string &a, const std::string &b): 
        _receiver(receiver), 
        _a(std::move(a)), 
        _b(std::move(b)) 
        {}

        void exec() const override 
        {
            std::cout << "ComplexCommand: Complex stuff should be done by a receiver object\n";
            _receiver->DoSomething(_a);
            _receiver->DoSomethingElse(_b);
        }
};
