#pragma  once

//INCLUDES
#include <iostream>
#include <string>
#include <utility>
#include <cstring>

/***
 * @brief Class MyString that allow for optimized contatination
 */
class MyString
{
	public:
		//Constructor
		MyString(const char* text = "");

		//Destructor
		~MyString();

		//Move onstructor
		MyString(MyString && string) noexcept;

		//Method that return a size
		int size() const;

		//Method that return a number of fragments(size of list)
		int fragments() const;

		//Method that return a const reference to the fragment
		const MyString & fragment(int i) const;

		//Overloaded operator +=
		void operator += (const char* text);

		//Overloaded operator += for move semantic
		void operator += (MyString && text);

		//Overloaded assignment operator
		void operator = (MyString && text) noexcept;

		//return an array of chars
		const char * str() const;

		//Method that helps to print out MyString by using overloaded operator <<
		void print(std::ostream & out) const;

		//Method that returns a last MyString object in linked list
		MyString * last();
	private:

		char * m_arr = nullptr; 			//An array of chars
		MyString * m_next = nullptr;		//Pointer to the next object MyString(linked list)
		unsigned m_size = 0;				//Size of an array of chars

};

//Overloaded operator << for class MyString
std::ostream & operator << (std::ostream &out, const MyString& other);
