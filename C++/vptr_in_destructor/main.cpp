#include <iostream>

class Base {
public:
	/* 
	The standard requires that the type of the object being destructed 
	is the type of the destructor being executed
	*/
	virtual ~Base() { // breakpoint here
		std::cout << "~Base: ";
		this->test(); // vptr has already been reset to point to Base's vtable
	};
	virtual void foo() const = 0;
	virtual void test() const {
		std::cout << "Base->test()\n";
	}
};

class Derived : public Base {
public:
	~Derived() {
		std::cout << "~Derived: ";
		this->test();
	}
	virtual void foo() const {
		std::cout << "Derived\n";
	}
	virtual void test() const {
		std::cout << "Derived->test()\n";
	}
};

/*
gdb:
	break ~Base
	break ~Derived
	info vtbl this - print vtable of current object
	print *this    - print current object, including vtable pointer
*/
int main()
{
	Base* base_ptr = new Derived;
	std::cout << "Constructed...\n";
	base_ptr->test();
	delete base_ptr;
	std::cout << "Destroyed...\n";
}
