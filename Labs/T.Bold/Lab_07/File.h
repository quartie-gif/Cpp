#pragma once 

#include <iostream>
#include <string>
#include <utility>

/***
*   @brief A class Thats represents a file
*/
class File
{
    public:

        //Constructor
        File(const std::string &name): _name(std::move(name)) {}

        //Virtual destructor
        virtual ~File() { std::cout << "About to delete " << _name << std::endl; }

        //Method that counts numer of spaces to print out correct output
        inline void spaces(unsigned n)
        {
            _spaces = n + 2;
        }

        //Method that is used to get conctrete file
        virtual File *get(std::string s);

        //Getter for _name field
        std::string getName() const { return _name; }

        //Method for printing
        virtual void print(std::ostream &out) const;

    protected:
        std::string _name;      //Name of file
        unsigned _spaces = 0;   //Counter for spaces
};

//Streaming a File
inline std::ostream& operator << (std::ostream& out, const File &file)
{
    file.print(out);
    return out;
}