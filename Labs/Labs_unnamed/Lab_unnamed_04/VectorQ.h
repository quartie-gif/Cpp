#pragma once


#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

void print_map(std::string_view comment , const std::map<std::string, unsigned>& m);

class VectorQ
{
public:
	VectorQ() = default;


	void print(const std::string &text) const
	{
		for(const auto &person: _queue)
		{
			person -> print();
		}
	}

	void add(std::unique_ptr<Person> person_to_add)
	{	
		_queue.push_back(std::move(person_to_add));
	}

	std::vector<Woman *> getWomen()
	{
		std::vector<Woman *> womens;

		for(auto &person: _queue)
		{
			if(!person->is_man())
			{
				womens.push_back(dynamic_cast<Woman*>(person.get()));
			}
		}

		return womens;
	}

	void haircut(const std::string name = " ") 
	{
		for(auto &person: _queue)
		{
			if(person->name() == name)
				person->haircut();
				if(person->done())
				{
					_queue.erase(std::find(_queue.begin(), _queue.end(), person));
				}
				break;
		} 

	}

	void shave(const std::string name = " ")
	{
		for(auto &person: _queue)
		{
			person->haircut();
			if(person->done())
			{
				_queue.erase(std::find(_queue.begin(), _queue.end(), person));
			}
			break;
		} 
	}

	void countNames() const
	{
		std::map<std::string, unsigned> count;

		for(const auto &person: _queue)
		{ 
			count.insert_or_assign(person->name(), ++count[person->name()]);
		} 
		print_map("",count);

	}

private:
	std::vector<std::unique_ptr<Person> > _queue;
};


void print_map(std::string_view comment  = "", const std::map<std::string, unsigned>& m = {})
{
    std::cout << comment;
    for (const auto& [key, value] : m) {
        std::cout << key << " = " << value  << std::endl;
    }
    std::cout << "\n";
}