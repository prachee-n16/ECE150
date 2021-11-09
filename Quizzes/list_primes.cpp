#include <iostream>

int main();

int main()
{
    int x = 0;
    int y = 0;

    std::cout << "List Primes Program" << std::endl;
    std::cout << "Enter first number: ";
    std::cin >> x;
    std::cout << "Enter second number: ";
    std::cin >> y;

    //LOGIC HERE to check if prime
    bool found_primes = true;

    for (int i{x}; i < y + 1; ++i)
    {
        bool is_prime = true;
        //std::cout << x << " " << y << " " << i << std::endl;
        for (int j{2}; j < i; ++j)
        {
            if (i % j == 0)
            {
                is_prime = false;
            }
        }

        if (is_prime == true)
        {
            std::cout << i << " ";
            found_primes = false;
        }
    }

    if (found_primes == true)
    {
        std::cout << "No primes in range." << std::endl;
    }

    //std::cout << "Primes in range:" << x << y;

    return 0;
}