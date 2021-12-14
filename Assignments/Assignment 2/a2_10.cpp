#include <iostream>

// Function declarations
int main();

// Function definitions

// int main()
//
// This program finds all prime factors of a given integer
// 'n' entered by the user.
//
// Exercises:
//   1. Make sure the user enters an integer that is greater
//      than or equal to 2, and if the user enters something
//      else, repeat the query.
//
//   2. Right now, if this program is asked to factor
//      the integer 1714739208, you get the answer
//           2, 2, 2, 3, 7, 13, 19, 31, 31, 43,
//      Note the trailing comma, and as you may suspect,
//      this is very unsatisfying.
//
//      You can fix this in one of two ways:
//       A. If an integer is the first one being printed,
//          just print that integer;
//          Otherwise, print a comma, a space and the integer.
//
//       B. If the possible factor equals n,
//              just print the integer with no trailing ", ".
//
//      With little doubt, Solution B is easier to implement
//      than Solution A; however, sometimes it is not possible
//      to determine when a sequence comes to an end.
//        - How would you implement Solution A?
//   3. Suppse you wanted the factors of 1714739208 to be
//      printed as follows:
//           2^3 * 3 * 7 * 13 * 19 * 31^2 * 43
//      How would you update your program to do this?

// Not implemented but theory
// store prev_num
// check if prev_num and curr_num are the same
// if so,
// have a exponent value that you can add to
// add it on to the number?

int main()
{
    int n{};
    std::cout << "Enter a positive integer to be factored: ";
    std::cin >> n;

    while (n < 2)
    {
        std::cout << "Integer out of bounds" << std::endl;
        std::cout << "Enter a positive integer to be factored: ";
        std::cin >> n;
    }

    int possible_factor{2};
    bool first_int = true;

    while (n > 1)
    {
        while (n % possible_factor == 0)
        {
            if (first_int == true)
            {
                first_int = false;
                std::cout << possible_factor;
            }
            else
            {
                std::cout << ", " << possible_factor;
            }
            n /= possible_factor;
        }

        // Ideally, we should go to the next highest prime,
        // but this works, too.
        ++possible_factor;
    }

    // We need to print add an end-of-line once we've listed
    // all of the factors.
    std::cout << std::endl;

    return 0;
}