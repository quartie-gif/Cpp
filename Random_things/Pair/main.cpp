#include <iostream>
#include <utility>

template<typename T>
struct ptr
{
	using value_type = T;
	explicit ptr(T *p): _p(p)
	{}


	T& operator * ()
	{
		return *_p;
	}

	T* operator -> ()
	{
		return _p;
	}

	T* _p;
};


template<typename T=int>
struct int_type
{
	operator int() const
	{
		return static_cast<int>(_val);
	}

	T _val;
};

using Int_type = int_type<>;


int main(int argc, char const *argv[])
{

	using Type_ptr = ptr<std::pair<Int_type, Int_type> >;
	Type_ptr t1 {new Type_ptr::value_type{}};

	(*t1).first = Type_ptr::value_type::first_type{3};
	t1->second = Type_ptr::value_type::second_type{2};
	std::cout<< t1->first._val<<" "<<t1->second<<std::endl;

	return 0;
}