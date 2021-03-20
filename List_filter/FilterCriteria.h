#pragma once

#include "Functors.h"
#include "functional"
#include "List.h"

/**
 * @brief divisibleBy class
 * @param m_fun(std::vector) - a vector of std::function<bool(int)>
*/

class FilterCriteria{
private:
    std::vector<std::function<bool(int)>> m_fun;
public:
    /**
     * @brief Funciton that adds the element to the vector.
     * @param fun(std::function<bool(int)>) - function that we want to add
     * @return void.
     */
    void add( std::function<bool(int)> fun);

    /**
      * @brief Funciton that returns a size of vector m_fun.
      * @return int.
      */
    int size() const;

    /**
     * @brief Funciton that get an element from vector m_fun at index i.
     * @param i(int) - index that we want to access
     * @return const std::function<bool(int)>&.
     */
    const std::function<bool(int)>& get(int i) const;
};