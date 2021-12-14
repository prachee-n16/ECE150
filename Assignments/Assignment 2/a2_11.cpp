// LINK: https://replit.com/@dwharder/1-14-Greatest-common-divisor#main.cpp

#include <iostream>

// Function declarations
int main();

// Function definitions

// int main()
//
// This program queries the user for two integers 'm' and 'n'
// calculates the greatest-common divisor of these numbers.
// By definition, the "greatest" common divisor must be
// positive (or at least zero) because all numbers are
// divisible by '1'.
//
// Exercises:
//   1. This code does not work if at least one of
//      the arguments is 0. The gcd( m, 0 ) == m, including
//      the case of calculating the gcd( 0, 0 ). Fix this
//      code so that it does not crash.
//
//   2. What is the exact operation that causes a
//      "Floating point exception (core dumped)" ?
//   x % i when i = 0

int main()
{
    int m{};
    int n{};

    std::cout << "Enter the first integer: ";
    std::cin >> m;

    if (m < 0)
    {
        m = -m;
    }

    std::cout << "Enter a second integer: ";
    std::cin >> n;

    if (n < 0)
    {
        n = -n;
    }

    // Make sure m >= n
    if (m < n)
    {
        int tmp{m};
        m = n;
        n = tmp;
    }

    if (n == 0)
    {
        n = m;
    }
    else
    {
        // Perform our gcd algorithm
        while (m % n != 0)
        {
            int rem{m % n};
            m = n;
            n = rem;
        }
    }

    std::cout << "The gcd is " << n << std::endl;

    return 0;
}
