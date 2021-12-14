// Link: https://replit.com/@dwharder/1-13-Finding-a-sum-of-squares#main.cpp

#include <iostream>

// Function declarations
int main();

// Function definitions

// int main()
//
// This program queries the user for an integer and
// attempts to find if that integer is the sum of two
// non-zero squares.
//
// Exercises:
//    1. Rewrite the first part of the function to
//       ensure the user enters an integer that is
//       greater than or equal to 1.
//
//    2. The outer for loop continues running so long
//       as 'm1 < n'.  Suppose 'm1*m1 >= n', is there
//       any point in continuing? Update the condition
//       so that we stop if this condition is satisfied.
//
//    3. The inner for loop continues iterating so long
//       as m2 < n, but suppose '(m1*m1 + m2*m2) > n',
//       is there any point in continuing? Update the
//       conditional statement to have the inner loop
//       end early if ever this condition is satisfied.

int main()
{
    int n{};
    std::cout << "Enter an integer: ";
    std::cin >> n;

    while (n < 1)
    {
        std::cout << "Integer out of bounds" << std::endl;
        std::cout << "Enter an integer: ";
        std::cin >> n;
    }

    bool is_found{false};

    int m1{};
    int m2{};

    for (m1 = 1; m1 < n; ++m1)
    {
        for (m2 = m1; m2 < n; ++m2)
        {
            if ((m1 * m1 + m2 * m2) == n)
            {
                is_found = true;
                break; // exits the inner for loop
            }
            if ((m1 * m1 + m2 * m2) > n)
            {
                break;
            }
        }
        if (m1 * m1 >= n)
        {
            break;
        }

        if (is_found)
        {
            break; // exits the outer for loop
        }
    }