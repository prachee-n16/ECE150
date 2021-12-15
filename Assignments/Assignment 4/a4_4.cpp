#include <iostream>

int main();
double product(double data[], std::size_t capacity);

double product(double data[], std::size_t capacity)
{
    double product{};

    for (int i = 0; i < capacity; i++)
    {
        product *= data[i];
    }
    return product;
}

int main()
{
    return 0;
}