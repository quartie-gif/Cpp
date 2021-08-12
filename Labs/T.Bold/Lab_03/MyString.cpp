#include "MyString.h"



MyString::MyString(const char* text):m_next(nullptr), m_arr(nullptr)
{
	m_arr = new char[sizeof(m_arr)/sizeof(m_arr[0]) + 1];
	strcpy(m_arr, text);
}


int MyString::size() const
{	
	int count = 0;
	const MyString *temp = this;
	while(temp != nullptr)
	{
		count += strlen(temp->m_arr);
		temp = temp->m_next;
	}
	return count;

}

int MyString::fragments() const
{
	int sum = 0;

	// implementation


	return sum;
}

void MyString::operator += (const char *text)
{
	MyString *temp = this;
	while(temp->m_next != nullptr)
	{
		temp = temp->m_next;
	}
	temp -> m_next = new MyString(text);
}

void MyString::print(std::ostream & out) const
{
	if(m_next)
	{
		for(int i=0; i<size(); ++i)
		{
			out << m_arr[i];
		}
		out << " ";
		m_next -> print(out);
	}
	else
	{
		for(int i=0; i<size(); ++i)
		{
			out << m_arr[i];
		}
	}
	
}

std::ostream & operator << (std::ostream &out, const MyString& other)
{
	other.print(out);
	return out;
}