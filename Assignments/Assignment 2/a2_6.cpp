// Link: https://repl.it/@dwharder/1-12-Scope-of-loop-variable#main.cpp
#include <iostream>

// Function declarations
int main();

// Function definitions
int main()
{
    int k{};

    // In this for loop, not only is 'k' incremented at the
    // end of each loop, but the user also has the option of
    // adding another integral value onto it with each iteration
    // of the loop.
    //
    // If 'k' were declared in the for loop, e.g.,
    //    for ( int k{0}; k < 20; ++k ) {
    // then it would be impossible to determine what
    // the final value of 'k' was that caused the loop
    // to terminate.

    // Exercises:
    //   What happens if you replace the 'k = 0' with
    //   'int k{0}'? Before you try compiling it, think
    //   what could happen, and what you'd expect the output
    //   to be as a result.
    for (k = 0; k < 20; ++k)
    {
        std::cout << "k = " << k << std::endl;

        int value{};
        std::cout << "Add what to 'k'? ";
        std::cin >> value;
    }
}
