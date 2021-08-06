#include <iostream>
#include <set>
#include <string>
#include <iterator>

using namespace std;

struct Person
{
	Person(const std::string &second , const std::string &first): _surname(first), _name(second) {}

	void print(std::ostream& s) const { s << _surname << " " << _name; }

	std::string _surname, _name;	

};

std::ostream& operator<<(std::ostream& str, const Person pers)
{
    pers.print(str);
	return str;
}

bool operator<(const Person & p1, const Person & p2)
{
    return p1._surname < p2._surname or p1._name < p2._name;
}


int main ()
{
	typedef	std::set<Person>  kontener_typ;
	kontener_typ c;
	c.insert(Person("Nowak","Jan"));
	c.insert(Person("Nowak","Adam"));
	c.insert(Person("Kowalski","Jan"));
	c.insert(Person("Nowak","Adam"));
	c.insert(Person("Iksinski","Adam"));
	std::copy (c.begin(), c.end(), std::ostream_iterator<Person>(std::cout, " "));
}



