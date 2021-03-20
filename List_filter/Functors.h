#pragma once

/**
 * @brief Functors namespace
*/

namespace Functors{
    /**
     * @brief divisibleBy class
     * @param m_number - a number that we want to divide by
    */
    class divisibleBy{
    private:
        int m_number;
    public:
        /**
         * Create a new object of divisibleBy class
         * @brief constructor
        */
       divisibleBy (int i);
        /**
         * @brief operator ()  overloading.
         * @param num(int) - number that we want to divide
         * @return bool
        */
       bool operator () (int num) const;
    };
    /**
     * @brief greaterThan class
     * @param m_number - a number that we want to check if sth is grater than it
    */
    class greaterThan{
    private:
        int m_number;
    public:
        /**
         * Create a new object of greaterThan class
         * @brief constructor
        */
        greaterThan(int i);
        /**
            * @brief operator ()  overloading.
            * @param num(int) - number that we want to check if is greater then m_number
            * @return bool
           */
        bool operator () (int num) const;
    };

}