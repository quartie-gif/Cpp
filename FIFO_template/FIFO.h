#include <iostream>
#include "Node.h"


template<typename T>
class FIFO
{
public:
	using value_type = T;
	FIFO() = default;
	~FIFO();
	FIFO & push_back(T element);
	FIFO & pop_back();
	unsigned size() const;
	Node<T> * first() const;
	Node<T> * last() const;

	void print() const;
private:
	unsigned m_size = 0;
	Node<T>* m_head = nullptr;
	Node<T>* m_tail = nullptr;
};

template<typename T>
FIFO<T>::~FIFO()
{

}

template<typename T>
FIFO<T> & FIFO<T>::push_back(T element)
{
	if(!m_head and !m_tail)
	{
		m_head = m_tail = new Node<T>(element);
	}
	else
	{
		m_tail -> m_next = new Node<T>(element);		
		m_tail = m_tail -> m_next;
	}
	m_size ++ ;
	return *this;
}

template<typename T>
FIFO<T> & FIFO<T>::pop_back()
{

	Node<T> * temp = m_head;

	while(temp -> m_next != m_tail)
	{
		temp = temp -> m_next;
	}

	m_tail = temp;
	delete temp -> m_next;

	m_size --;


	return *this;
}

template<typename T>
unsigned FIFO<T>::size() const
{

	return m_size;
}

template<typename T>
Node<T> * FIFO<T>::first() const
{
	return *m_head;
}

template<typename T>
Node<T> * FIFO<T>::last() const
{
	return *m_tail;
}

template<typename T>
void FIFO<T>::print() const
{

	Node<T> * temp = m_head;

	do
	{
		std::cout << *temp << " "; 
		temp = temp -> m_next;
	}while(temp != m_tail -> m_next);

	std::cout << std::endl;
}

