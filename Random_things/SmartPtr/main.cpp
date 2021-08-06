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


	/*
	---------------- TESTING UNIQUE POINTER ----------------
	*/

	std::cout << std::endl;

	MyInt* myInt15 = new MyInt(15);
	std::unique_ptr<MyInt> uniquePtr1(myInt15);
	// std::unique_ptr<MyInt> uniquePtr15(myInt15);

	std::cout << "uniquePtr1.get(): " << uniquePtr1.get() << std::endl;

	std::unique_ptr<MyInt> uniquePtr2{std::move(uniquePtr1)};
	std::cout << "uniquePtr1.get(): " << uniquePtr1.get() << std::endl;
	std::cout << "uniquePtr2.get(): " << uniquePtr2.get() << std::endl;

	std::cout << std::endl;


	std::cout << "Before local scope" << std::endl; 

	{
	  std::unique_ptr<MyInt> localPtr{new MyInt(2003)};
	}

	std::cout << "After local scope" << std::endl; 

	std::cout << std::endl;

	uniquePtr2.reset(new MyInt(2011));
	MyInt* myInt= uniquePtr2.release();
	delete myInt;

	// std::cout << std::endl;


	/*
	---------------- TESTING SHARED POINTER ----------------
	*/

	std::shared_ptr<int> sharedPtr1(new int{11}, IntDeleter());

	std::cout << "Before local scope" << std::endl; 


	//Define a local scope
	{
		std::shared_ptr<int> sharedPtr1(new int{7}, IntDeleter());
		std::shared_ptr<int> sharedPtr2(new int(6), IntDeleter());
		IntDeleter* intDeleter = std::get_deleter<IntDeleter>(sharedPtr1);
		intDeleter->info();
		sharedPtr2.reset();
		std::cout << sharedPtr2.use_count() << std::endl;
		std::cout << sharedPtr1.use_count() << std::endl;
		intDeleter->info();
	}

	std::cout << "After local scope" << std::endl; 

	/*
	---------------- TESTING WEAK POINTER ----------------
	*/


	std::cout << std::boolalpha << std::endl;

	auto sharedPtr3 = std::make_shared<int>(2042);
	std::weak_ptr<int> weakPtr(sharedPtr3);

	std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;
	std::cout << "sharedPtr3.use_count(): " << sharedPtr3.use_count() << std::endl;
	std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;

	auto sharedPtr4 = std::make_shared<int>(1234);

	if( std::shared_ptr<int> sharedPtr1 = weakPtr.lock() )
	{
		std::cout << "*sharedPtr3 (value): " << *sharedPtr3 << std::endl;
		std::cout << "sharedPtr3.use_count(): " << sharedPtr3.use_count() << std::endl;
	}
	else
	{
		std::cout << "Couldn't get the source!!"  << std::endl;
	}

	std::cout << std::endl;
	std::cout << "sharedPtr3.use_count(): " << sharedPtr3.use_count() << std::endl;
	std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;
	std::cout << std::endl;
	return 0;
}


