#include "ErrorClass.h"

std::vector<Calc_error*> Calc_error::_errors{};

void Calc_error::handler()
{
	std::cout << " Zlapano wyjatek: \n";

	for(auto *it: _errors)
	{
		if(_errors.size() == 1)
		{
			std::cout << " -- z powodu: " << it->what();
			delete it;
			break;
		}
		it->print();
		delete it;
	}
}