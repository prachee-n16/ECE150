#include <iostream>

int main();
void print_complex(double a, double b);

void print_complex(double a, double b)
{
    a = 1;
    b = -3;

    if (b > 0)
    {
        std::cout << a << " + " << -b << "j" << std::endl;
    }
    if (b < 0)
    {
        std::cout << a << " - " << -b << "j" << std::endl;
    }
}

int main()
{
    print_complex(1, -3);
    return 0;
}