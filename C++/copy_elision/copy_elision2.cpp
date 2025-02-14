#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

struct Foo {
	Foo(std::size_t length, char value) : data(length, value)
	{
		std::cout << "*** DEFAULT ***" << std::endl;
	}

	Foo(const Foo& rhs) : data(rhs.data)
	{
		std::cout << "*** COPY ***" << std::endl;
	}

	Foo& operator=(Foo rhs)
	{
		std::cout << "*** ASSIGNMENT ***" << std::endl;
		std::swap(data, rhs.data); // probably expensive, ignore this please
		return *this;
	}

	// Foo& operator=(const Foo& rhs)
	// {
	// 	std::cout << "*** ASSIGNMENT ***" << std::endl;
	// 	Foo tmp(rhs);
	// 	std::swap(data, tmp.data); // probably expensive, ignore this please
	// 	return *this;
	// }

	// Foo& operator=(Foo&& rhs)
	// {
	// 	std::cout << "*** ASSIGNMENT ***" << std::endl;
	// 	std::swap(data, rhs.data); // probably expensive, ignore this please
	// 	return *this;
	// }

	~Foo() { std::cout << "*** DESTRUCTION ***" << std::endl; }

	std::vector<char> data;
};

Foo TestRVO()
{
	return Foo(512, 'r');
}

Foo TestNamedRVO()
{
	Foo result(512, 'n');
	return result;
}

void PassByValue(Foo inFoo) {}

int main()
{
	{
		std::cout << "\nTest RVO: " <rhs
		std::cout << "\nTest named RVO: " << std::endl;
		Foo named_rvo = TestNamedRVO();
	}
	{
		std::cout << "\nTest PassByValue: " << std::endl;
		Foo foo(512, 'a');
		PassByValue(foo);
	}
	{
		std::cout << "\nTest assignment: " << std::endl;
		Foo f(512, 'f');
		// Foo g(512, 'g');
		f = Foo(512, 'g');
	}
}
