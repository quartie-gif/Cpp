#pragma once

#include <iostream>
#include <vector>


// Structure that can store any kind of object to allow casting dynamically
struct ABC {
 	virtual ~ABC()=default;
};

//Template to store objects of any class
template <typename T> 
struct AnyClass: public ABC {
	
    //Stores an object
    T _value;

    //Constructor
	AnyClass(T & el): ABC(), _value(el)
    {

    }

    //Default destructor
    ~AnyClass()=default;

    //Getter
	T & get() {
		return _value;
	}


};

/***
*   @brief Factory class that allows constructing and cloning an object of any kind
*/
class ClonesF
{
    public:

        //Method that adds objects of type T 
        template<typename T>
        void add(T &object)
        {
            _vec.push_back(new AnyClass<T>(object));
        }

        //Method that clones an object
        template<typename T>
        T & clone()
        {
            AnyClass<T> *temp = nullptr;

            for(const auto &it: _vec)
            {
                temp = dynamic_cast<AnyClass<T> *>(it);
                if(temp) return temp->get();
            }
            return temp->get();
        }

        //Method that replaces an object
        template <typename T>
        void replace(const T & object)
        {
            AnyClass<T> * temp = nullptr;
            for(const auto &it: _vec) 
            {
                temp = dynamic_cast<AnyClass<T> * >(it);
                if (temp) temp->_value = object;
            }

        }

        ~ClonesF() {
            for (auto it: _vec) {
                delete it;
            }
        }

    private:
        std::vector<ABC *> _vec;
};

