#include "CircleLinkedList.h"



CircledLinkedList::CircledLinkedList(std::string name): m_head(nullptr), m_name(std::move(name))
{

}
CircledLinkedList::~CircledLinkedList()
{	
	std::cout << "DESTRUCTOR CALLED FOR " << m_name << " ! " << std::endl;
	if(m_head != nullptr)
	{
		Node *temp = m_head;
		do
		{
			Node* next = temp->m_next;
			delete temp;
			temp = next;
		}while(temp != m_head);

		std::cout << "All nodes has been freed successfully!" << std::endl;
	}
	else
	{
		std::cout << "No data to leak!" << std::endl;
	}
}

CircledLinkedList::CircledLinkedList(const CircledLinkedList &other): m_head(nullptr)
{
	// Deep copy
	std::cout << "COPY CONSTRUCTOR CALLLED! " << std::endl;

	Node *temp = other.m_head;
	do
		{
			addNode(temp->m_data);

			temp = temp->m_next;
			
		}while(temp != other.m_head);	

	std::cout << "All nodes has been copied successfully!" << std::endl;



}

// CircledLinkedList& CircledLinkedList::operator = (const CircledLinkedList &other)
// {
// 	std::cout << "OPERATOR = CALLED" << std::endl;

// 	if (this == &other)
// 	{
//         return *this;
// 	}
//     else
//     {
//     	Node *temp = other.m_head;
// 	do
// 		{
// 			addNode(temp->m_data);

// 			temp = temp->m_next;
			
// 		}while(temp != other.m_head);

// 		return *this;	
//     }
// }



Node* CircledLinkedList::addNode(int data)
{
	if(m_head == nullptr)
	{
		m_head = new Node(data);
		m_head -> m_next = m_head;
		std::cout << "Node " << data << " has been appended at the head!" << std::endl;
	}
	else
	{
		Node *temp = m_head;
		do
		{
			temp = temp -> getNext();
		}while(temp -> getNext() != m_head);
		temp -> m_next = new Node(data);
		temp -> m_next -> m_next = m_head;
		std::cout << "Node " << data << " has been appended!"<< std::endl;
		return temp;
	}
	return nullptr;
}

CircledLinkedList* CircledLinkedList::operator + (int data)
{
	addNode(data);
	return this;
}

Node* CircledLinkedList::operator [] (int index)
{
	std::cout << "OPERATOR [] CALLED" << std::endl;
	int i = 0;
	if(m_head != nullptr)
	{	
		Node *temp = m_head;
		do
		{
			if(i == index)
			{
				 return temp;
			}
			std::cout << temp -> m_data;
			temp = temp -> getNext();
			++i;
		}while(temp!= m_head);
	}
	else 
	{	

		std::cout << "List is empty!" << std::endl;
	}
	return nullptr;

}


std::ostream &operator << (std::ostream &strm, const CircledLinkedList &other)
{	
	strm << "Printing CircledLinkedList " << other.m_name << std::endl;
	if(other.m_head != nullptr)
	{
		Node *temp = other.m_head;
		do
		{
			strm << temp -> getData() << " ";
			temp = temp -> getNext();
		}while(temp!= other.m_head);
	}
	else 
	{
		strm << "List is empty!" << std::endl;
	}
	strm << std::endl;
	return strm;
}
