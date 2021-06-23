#include <iostream>
#include <string>
#include <utility>



class Node{
	friend std::ostream &operator << (std::ostream &strm, const Node &other);
	friend class CircledLinkedList;
public:
	explicit Node(int  data);
	~Node();

	int getData() const;
	Node *getNext() const;
private:
	int m_data;
	Node* m_next;
};

std::ostream &operator << (std::ostream &strm, const Node &other);