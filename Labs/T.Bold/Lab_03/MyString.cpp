#include "MyString.h"



MyString::MyString(const char* text): m_arr(nullptr), m_next(nullptr)
{
	m_size = strlen(text);
	m_arr = new char[m_size + 1];
	strcpy(m_arr, text);

}

MyString::~MyString()
{
	if(m_arr) delete[] m_arr;
}

MyString::MyString(MyString && string) noexcept:
m_arr(std::exchange(string.m_arr, nullptr)),
m_next(std::exchange(string.m_next, nullptr)),
m_size(std::exchange(string.m_size, 0))
{
}

int MyString::size() const
{	
	int count = 0;
	const MyString *temp = this;
	while(temp != nullptr)
	{
		count += temp->m_size;
		temp = temp->m_next;
	}
	return count;

}
int MyString::fragments() const
{
	const MyString *temp = this;
    int count = 0;
    while(temp->m_next){
      temp = temp->m_next;
      count ++;
    }
    return ++ count;

}

const MyString & MyString::fragment(int i) const{

    const MyString * temp = this;
    for (int j = 0; j < i; j++)
        temp = temp->m_next;
    return *temp;
}

void MyString::operator += (const char *text)
{
	MyString *temp = last();
	temp -> m_next = new MyString(text);
}

void MyString::operator += (MyString && text)
{
	m_next = &text;
}

void MyString::operator = (MyString && string) noexcept
{
	if(this != &string)
	{
		m_size = string.m_size;
		m_arr = string.m_arr;
		m_next = string.m_next;
		string.m_size = 0;
		string.m_arr = nullptr;
		string.m_next = nullptr;
	}
}

const char * MyString::str() const
{
    return m_arr;
}

void MyString::print(std::ostream & out) const
{
	if(m_size > 0)
	{
		for (size_t i = 0; i < fragments(); i++)
		{
			out << fragment(i).str();
		}
		
	}
	
}

MyString * MyString::last()
{
    MyString * temp = this;
    while(temp->m_next){
      temp = temp->m_next;
    }
    return temp;

}


std::ostream & operator << (std::ostream &out, const MyString& other)
{
	other.print(out);
	return out;
}