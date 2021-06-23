#include <iostream>
#include <memory>
#include <algorithm>
#include <random>
#include <map>
#include <array>
#include "class.h"

int main()
{
	auto skoda = std::make_shared<Car>("Skoda");
	auto bmw = std::make_shared<Car>("BMW");
	auto citroen = std::make_shared<Car>("Citroen");

    std::cout << "--------------- std::map testing ---------------\n";

	std::map<std::string, std::shared_ptr<Car> > choicesMap {{"Skoda", skoda}, {"BMW", bmw}, {"Citroen", citroen}};

	for (const auto& [key, value] : choicesMap) {
       std::cout << key << " = " << value->getBrand() << "; ";
    }

    std::cout << "\n--------------- std::array testing ---------------\n";
	
	std::array<std::shared_ptr<Car> , 3> arr {skoda, bmw, citroen};

	for(const auto& el: arr)
    	std::cout << el->getBrand() << ' ';
 
	Cars<Car > katalog;
	katalog.add(skoda).add(bmw).add(citroen);
	katalog.print();
	return 0;
}
