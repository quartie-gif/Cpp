// 2. słowo kluczowa mutable + podać przykład kodu
// 3. klasa abstrakcyjna
// 4. STL - uzupełnij kod
// 5. Kod:
// uzupełnij 

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

struct A 
{
	static int counter;

	void operator () (int& i)
	{
		i = counter;
		counter --;
	}

};

int A::counter = -1;

int main() 
{
	list<int> coll(11);
	for_each( std::begin(coll), std::end(coll), A() );
	copy( std::begin(coll), std::end(coll), std::ostream_iterator<int>(std::cout, "; ") );
	return 0;
}



