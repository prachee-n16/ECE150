#include <iostream>

int main();
void f();

int main()
{
    std::cout << "In main()" << std::endl;
    f();
    return 0;
}
void f()
{
    int *p_value{new int{43}};
    std::cout << "In f(): " << p_value << std::endl;
    *p_value = 42;
}