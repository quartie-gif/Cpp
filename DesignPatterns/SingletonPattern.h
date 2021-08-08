#pragma once

#include <iostream>

template<typename T>
class Singleton
{
    public:
        using value_type = T;

        static Singleton& instance()
        {
            static Singleton* instance = new Singleton();
            return *instance;
        }
            
        // Getter functions
        T getFirstParameter() const;
        T getSecondParameter() const;

        // Setter functions
        void setFirstParameter(T arg);
        void setSecondParameter(T arg);

    private:

        //Hidden Constructor
        Singleton();
        ~Singleton();
        //Member variables
        T m_firstParameter;
        T m_secondParameter;
};

template<typename T>
Singleton<T>::Singleton()
{

}

template<typename T>
Singleton<T>::~Singleton()
{

}


template<typename T>
T Singleton<T>::getFirstParameter() const
{
    return m_firstParameter;
}
template<typename T>
T  Singleton<T>::getSecondParameter() const
{
    return m_secondParameter;
}

template<typename T>
void Singleton<T>::setFirstParameter(T arg)
{
    m_firstParameter = arg;
}

template<typename T>
void Singleton<T>::setSecondParameter(T arg)
{
    m_secondParameter = arg;
}

