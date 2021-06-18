// 1. Opisz dynamic_cast, zaprezentuj przykłady kodu.
/* 
*	Safely converts pointers and references to classes up, down, and sideways
*	along the inheritance hierarchy.
	
Przykład:

#include <iostream>

struct Parents
{
	Parents() {std::cout << "Parents";}
};

struct Child: public Parents
{
	Child() {std::cout << "Child";}
};

int main()
{
	Child *child = new Child();
	if(Parents* parent  = dynamic_cast<Parents*>(child))
	{
		std::cout << "Sucessfully!";
	}
	return 0;
}

*/ 

// Kontenery z STLa (charakterystyka, podział, kwestie bezpieczeństwa itp.)

/*
Podział 
*****	Sequence:

	*	- template< class T, std::size_t N> struct array - defined in header <array> fixed(stałe) size arrays.
	
		Ciekawostka: There is a special case for a zero-length array (N == 0). In
		that case, array.begin() == array.end(), which is some unique value.
		The effect of calling front() or back() on a zero-sized array is undefined.

	*	- template<class T,class Allocator = std::allocator<T>> class
		  vector; - std::vector is a sequence container that encapsulates
		  dynamic size arrays.
	
	*	- template<class T,class Allocator = std::allocator<T>> class list -
		  is a container that supports constant time insertion and removal
		  of elements from anywhere in the container. Fast random access is
		  not supported. It is usually implemented as a doubly-linked list.
		  Compared to std::forward_list this container provides
		  bidirectional iteration capability while being less space efficient.

*****	Associative:
	
	*	- template<class Key,class Compare = std::less<Key>,class Allocator = std::allocator<Key>> class set;
		std::set is an associative container that contains a sorted set of unique objects of type Key.

	*	- template<class Key,
    				class T,
    				class Compare = std::less<Key>,
    				class Allocator = std::allocator<std::pair<const Key, T> >
				> class map;

		std::map is a sorted associative container that contains key-value
		pairs with unique keys. Keys are sorted by using the comparison
		function Compare.

*****	Unordered associative:
		cpprefernce jak interesujące...

*****	Adaptors:
	*	- template<class T,class Container = std::deque<T>> class stack;

	- The std::stack class is a container adapter that gives the programmer
	  the functionality of a stack - specifically, a LIFO(last-in, first-out)
	  data structure.

	 *	- template<class T,class Container = std::deque<T>> class queue;

	- The std::queue class is a container adapter that gives the programmer
	  the functionality of a queue - specifically, a FIFO
	  (first-in, first-out) data structure


*****	Views:

Example: std::span
 		The class template span describes an object that can refer to
*    	a contiguous sequence of objects with the first element of the
*    	sequence at position zero. A span can either have a static
*    	extent, in which case the number of elements in the sequence is
*    	known at compile-time and encoded in the type, or a dynamic extent.
*/	

/*uzupelnij*/


#include <iostream>
#include <string>
#include <set>
#include <iterator>


int main(){
//tu stworzone zostaly obiekty normal_order i reverse_order, ale nie pamietam jak to dokladnie wygladalo
	typedef std::set<std::string> kontener_typ;
	
	struct normal_order
	{
		bool operator () (const std::string& str1, const std::string& str2) const 
		{
			return str1 < str2;
		}

	}normal_order;

	struct reverse_order
	{
		bool operator () (const std::string& str1, const std::string& str2) const
		{
			return str1 > str2;
		}

	}reverse_order;


	kontener_typ c(normal_order);
	c.insert("abc");
	c.insert("def");
	c.insert("ghi");
	c.insert("jkl");
	copy(c.begin(), c.end(), std::ostream_iterator<std::string>(std::cout, ", "));
	kontener_typ d(reverse_order);
	//tu byl jakis kod
	// copy(c.begin(), c.end(), /*uzupelnij*/);
	// copy(d.begin(), d.end(), std::ostream_iterator<std::string>(std::cout, ", "));
	//tu byl jakis kod
}
//program mial wypisac te 4 stringi w porzadku alfabetycznym a potem odwrotnym



