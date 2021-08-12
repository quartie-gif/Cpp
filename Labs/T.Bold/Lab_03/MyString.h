#pragma  once
#include <iostream>
#include <string>
#include <cstring>

/*MyString::size zwraca olisc znakow w napisie (lacznie z dlugoscia w "podlinkowanych" napisach).
MyString::fragments zwraca ilosc fragmentow (dlugosc listy)
MyString::fragment(i) zwraca MyString z listy polaczonej (0 to jej poczatek itd.)
MyString::str() zwraca znaki (const char*) zlozone w danym fragmencie.*/

class MyString
{
	public:
		MyString(const char* text = "");
		int size() const;
		int fragments() const;
		void operator += (const char* text);
		void print(std::ostream & out) const;
	private:
		char * m_arr;
		MyString * m_next;

};


std::ostream & operator << (std::ostream &out, const MyString& other);
