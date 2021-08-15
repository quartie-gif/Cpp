#pragma once 

//INLCUDES
#include <iostream>
#include <vector>
#include <string>
#include "File.h"

/***
*   @brief A class Thats represents a directory. It can't be inharited because of keyword final
*/
class Dir final: public File 
{
    public:

        //Constructor
        Dir(const std::string &s);

        //Destructor
        ~Dir();

        //Overloaded operator += that addd a file to the vector of *Files
        void operator += (File *file);

        //Method that addd a file to the vector of *Files
        void add(File *file);

        //Method that is used to find a directory
        Dir * findDir(const std::string &s);

        //Method for printing a directory
        void print(std::ostream &out) const;

        //Method for getting a vector of pointers to Files
        const std::vector< File*> & getFiles() const { return _files; }

    private:
        std::vector< File*> _files; // Vector of pointers to Files
};

