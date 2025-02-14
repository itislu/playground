#include <iostream>

class Base {
public:
	Base() {
		std::cout << "Base()" << '\n';
	}
	virtual ~Base() { // Clang puts ud2 instruction in destructor for heap allocation
		std::cout << "~Base()" << '\n';
	}
	virtual void func() = 0;

	void operator delete(void* ptr) {};
};

class Derived : public Base {
public:
	Derived() {
		std::cout << "Derived()" << '\n';
	}
	~Derived() {
		std::cout << "~Derived()" << '\n';
	}
	void func() {
		std::cout << "Derived->func()" << '\n';
	}
};

/*
gdb:
	break ~Base
	break ~Derived
	info vtbl this - print vtable of current object
	print *this    - print current object, including vtable pointer
*/
int main(void)
{
	/* Call pure virtual function in heap allocated object */
	{
		Derived* derived_ptr = new Derived();
		derived_ptr->~Derived();
		derived_ptr->func();
	}

	/* Call pure virtual function in stack allocated object */
	{
		Derived derived;
		Base* base_ptr = &derived;
		base_ptr->~Base();
		base_ptr->func();
	}

	/* 'objdump -dC', checkout Base::~Base() and search for ud2 instruction */
	{
		Derived* derived_ptr = new Derived();
		delete derived_ptr; // Call ~Derived() and ~Base() -> reset vptr to vtbl of Base
		delete derived_ptr; // Call other destructor of ~Base() which should never be called
	}
}
