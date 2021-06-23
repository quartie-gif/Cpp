#pragma once 



template<typename T>
struct Node
{
	Node() = default;
	~Node() { m_next = nullptr; }
	Node(T val): m_val(val) {}
	inline void print() const
	{
		std::cout << m_val;
	}

	T m_val;
	Node<T>* m_next = nullptr;
};

template<typename T>
std::ostream & operator << (std::ostream &o, const Node<T> &node)
{
	node.print();
	return o;
}