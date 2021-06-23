#include <iostream>
#include "CircleLinkedList.h"



int main(void) 
{
	std::cout << "\n------------- CIRCURAL LINKED LIST -------------\n" << std::endl;
	CircledLinkedList* FirstList = new CircledLinkedList("First List");
	CircledLinkedList* SecondList = new CircledLinkedList("Second List");
	CircledLinkedList* ThirdList = new CircledLinkedList("Third List");

	std::cout << "\n------------- ADDING NODES -------------" << std::endl;
	std::cout << "\nFirst List\n"; 
	FirstList -> addNode(13);
	FirstList -> addNode(101);
	FirstList -> addNode(9978);
	FirstList -> addNode(0);

	std::cout << "\nSecond List\n"; 
	SecondList -> addNode(420);
	SecondList -> addNode(76);
	SecondList -> addNode(30595);
	SecondList -> addNode(1230);
	*SecondList+43;

	std::cout << "\nThird List\n"; 
	
	*(*ThirdList+54)+32;
	*ThirdList+33;

	std::cout << "\n------------- PRINTING -------------" << std::endl;

	std::cout << *FirstList << std::endl;
	std::cout << *SecondList << std::endl;
	std::cout << *ThirdList << std::endl;

	// std::cout << "\n------------- TESTING [] OPERATOR -------------" << std::endl;

	// Node* temp = *ThirdList[2];

	// std::cout << *temp << std::endl;

	std::cout << "\n------------- COPYING -------------" << std::endl;

	CircledLinkedList CopiedFirstList = *FirstList;


	std::cout << "\n------------- PRINTING COPIED LIST -------------" << std::endl;

	std::cout << CopiedFirstList;

	std::cout << "\n------------- FREEING -------------" << std::endl;

	delete FirstList;
	delete SecondList;
	delete ThirdList;


	std::cout << "\n------------- END OD PROGRAM -------------\n" << std::endl;

	return 0;
}

