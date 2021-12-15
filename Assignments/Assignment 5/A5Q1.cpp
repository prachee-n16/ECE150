// What is the difference & similarities between a local var that is
// a pointer and another local var that is a double

// double stores a double-precision 64-bit IEEE 754 floating point
// pointer stores an address or the memory location of another variable or another pointer variable.

// Given the declarations below, how much space is allocated on the call stack

#include <iostream>
int main();

int main()
{
    int x{};
    int *p_x{};
    int y{};
    int *p_y{};

    std::cout << &x << std::endl;
    std::cout << &p_x << std::endl;
    std::cout << &y << std::endl;
    std::cout << &p_y << std::endl;
}
