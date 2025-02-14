#include <iostream>

int main ()
{
	int *p = NULL;
	int &r = *p;

	std::cout << &r << std::endl;
	// std::cout << r << std::endl; // Would segfault
}
