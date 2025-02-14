#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>
#include <sstream>

class A {
public:
    A() : _ptr(new char[42]) {}
    ~A() { delete[] _ptr; }

private:
    char* _ptr;
};

int main(int argc, char* argv[])
{
    int amount = 0;
    if (argc > 1) {
        std::istringstream(argv[1]) >> amount;
    }

    A* array = new A[amount];

    std::cout << "newed size: " << *(reinterpret_cast<size_t*>(array) - 1)
              << '\n';

    /* Correct */
    delete[] array;

    /* Invalid free */
    // delete array;

    /* Segmentation fault (no object with destructor at that address) */
    // delete (reinterpret_cast<size_t*>(array) - 1);

    /* No segmentation fault (pure free, no destructor call) */
    // operator delete(reinterpret_cast<size_t*>(array) - 1);
}
