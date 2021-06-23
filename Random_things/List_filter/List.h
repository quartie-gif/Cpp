#pragma once

#include <iostream>
#include <vector>

/**
 * @brief List class that immitates an array of integers
 */

class List{
private:
    std::vector<int> m_list;
public:
    /**
     * Create a new List object
     * @brief Default constructor
     */
    List() = default;

    /**
     * Delete an object
     * @brief Default deconstructor
     */
    ~List() = default;

    /**
     * @brief Insert an element to the list.
     * @return void.
     */
    void insert(int x);

    /**
     * @brief Funciton that prints out a list.
     * @return void.
     */
    void print(const char* text = "") const;

    /**
     * @brief Filtering a list.
     * @param fun -  polymorphic function wrapper
     * @return List.
     */
    List filter(const std::function<bool(int)>& fun);

    /**
   * @brief operator []  overloading.
   * @param fun -  polymorphic function wrapper
   * @return The reference to the element of list.
   */
    int& operator [] (int index);
};