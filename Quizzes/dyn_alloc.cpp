#include <iostream>

//Functions to be made
int *allocateInt(int n);
char *allocateChar(char n);
double *allocateDouble(double n);
void deallocateInt(int *n);
void deallocateChar(char *n);
void deallocateDouble(double *n);

int *allocateInt(int n)
{
    int *p_n;

    p_n = new int{n};
    return p_n;
}
char *allocateChar(char n)
{
    char *p_n;
    p_n = new char{n};
    return p_n;
}
double *allocateDouble(double n)
{
    double *p_n;
    p_n = new double{n};
    return p_n;
}

void deallocateInt(int *n)
{
    delete n;
    n = nullptr;
}
void deallocateChar(char *n)
{
    delete n;
    n = nullptr;
}
void deallocateDouble(double *n)
{
    delete n;
    n = nullptr;
}

#ifndef disable_main
int main();
#endif

#ifndef disable_main
int main()
{
    int x{};
    std::cout << "What is the int?: ";
    std::cin >> x;
    char y{};
    std::cout << "What is the char?: ";
    std::cin >> y;
    double z{};
    std::cout << "What is the double?: ";
    std::cin >> z;

    int *a = allocateInt(x);
    char *b = allocateChar(y);
    double *c = allocateDouble(z);

    std::cout << "The integer's value is " << *a << std::endl;
    std::cout << "The char's value is " << *b << std::endl;
    std::cout << "The double's value is " << *c << std::endl;

    std::cout << "The integer's address is " << a << std::endl;
    std::cout << "The char's address is " << &b << std::endl;
    std::cout << "The double's address is " << c << std::endl;

    deallocateInt(a);
    deallocateChar(b);
    deallocateDouble(c);
    return 0;
}
#endif