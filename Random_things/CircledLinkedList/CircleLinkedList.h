#include <iostream>
#include <string>
#include <utility>
#include "Node.h"

class CircledLinkedList {
	friend std::ostream &operator << (std::ostream &strm, const CircledLinkedList &other);
public:
	CircledLinkedList(std::string name);
	~CircledLinkedList();
	CircledLinkedList(const CircledLinkedList &other);
	Node* addNode(int data);
	CircledLinkedList* operator + (int data);
	Node* operator [] (int index);

private:
	Node* m_head;
	std::string m_name;
};

std::ostream &operator << (std::ostream &strm, const CircledLinkedList &other);
 