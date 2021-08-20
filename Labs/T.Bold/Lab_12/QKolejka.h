#pragma once 

#include <iostream>
#include <list>
#include <string>
#include <functional>

template<typename T>
class QKolejka
{
    public:

        using const_reverse_iterator = typename std::list<T>::const_reverse_iterator;
	    using const_iterator = typename std::list<T>::const_iterator;

        QKolejka(std::function<bool(T)> fun): _compare(fun)
        {
            
        } 

        void dodaj(const T &person)
        {
            if(_queue.empty()) _queue.push_back(person);
            else
            {
                for(auto it = _queue.begin(); it != _queue.end(); ++it)
                {
                    if(_compare(*it) > _compare(person))
                    {
                        _queue.insert(it, person);
                        return;
                    }
                }
                _queue.push_back(person);
            }

        }

        void dodaj(std::initializer_list<T> list) 
        {
            for (auto &it: list)    dodaj(it);
        }

        const_iterator begin() const 
        {
            return _queue.begin();
        }

        const_iterator end() const 
        {
            return _queue.end();
        }

        const_reverse_iterator rbegin() const 
        {
            return _queue.rbegin();
        }

        const_reverse_iterator rend() const 
        {
            return _queue.rend();
        }
    private:
        std::function <bool(T)> _compare;
        std::list<T> _queue = {};
};