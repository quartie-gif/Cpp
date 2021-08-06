#include <iostream>
#include <utility>
#include <memory>

#include "main.h"

using IntDeleter = Deleter<int>;

int main(int argc, char const *argv[])
{
	/*
	---------------- TESTING SMART POINTERS ----------------
	*/

	//Define a local scope
	{
		std::shared_ptr<int> sharedPtr1(new int{7}, IntDeleter());
		std::shared_ptr<int> sharedPtr2(new int(6), IntDeleter());
		auto intDeleter = std::get_deleter<IntDeleter>(sharedPtr1);
		intDeleter->info();
		sharedPtr2.reset();
		std::cout << sharedPtr2.use_count() << std::endl;
		std::cout << sharedPtr1.use_count() << std::endl;
		intDeleter->info();
	}



	return 0;
}


