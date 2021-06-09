#include <iostream>
#include "FIFO.h"


int main() 
{

	std::cout << "--------TESTING FIFO--------" << std::endl;

	FIFO<int> fifoINT;
	fifoINT.push_back(3).push_back(4).push_back(5).push_back(13).push_back(-2442);
	fifoINT.print();
	fifoINT.size();
	fifoINT.pop_back();
	fifoINT.print();

	return 0;
}