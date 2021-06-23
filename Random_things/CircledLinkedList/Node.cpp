#include "Node.h"

Node::Node(int data): m_data(std::move(data)), m_next(nullptr)
{

}
Node::~Node()
{

}
int Node::getData() const
{
	return m_data;
}

Node *Node::getNext() const
{
	return m_next;
}


std::ostream &operator << (std::ostream &strm, const Node &other)
{
	std::cout << "OPERATOR << for NODE CALLED " <<std::endl ;
	return strm << other.m_data;
}