// Link: https://repl.it/@dwharder/1-12-Scope-of-variables-exercise

#include <iostream>

// Function declarations
int main();

// Function definitions

// This program does not compile because many of the local
// variables are referred out outside of their scope.
//
// Erase those local variables being printed that are not
// in scope.
int main()
{
    int v1{1};
    std::cout << v1 << std::endl;

    for (int v2{0}; v2 < 10; ++v2)
    {
        std::cout << v1 << v2 << std::endl;
        int v3{3};
        std::cout << v1 << v2 << v3 << std::endl;

        if (v2 > 5)
        {
            std::cout << v1 << v2 << v3 << std::endl;
            int v4{4};
            std::cout << v1 << v2 << v3 << v4 << std::endl;
        }
        else
        {
            int v5{5};
            std::cout << v1 << v2 << v3 << v5 << std::endl;
        }

        std::cout << v1 << v2 << v3 << std::endl;
        int v6{6};
        std::cout << v1 << v2 << v3 << v6 << std::endl;

        for (int v7{0}; v7 < 10; ++v7)
        {
            std::cout << v1 << v2 << v3 << v6 << v7 << std::endl;

            if (v2 + v7 < 5)
            {
                std::cout << v1 << v2 << v3 << v6 << v7 << std::endl;
                int v8{8};
                std::cout << v1 << v2 << v3 << v6 << v7 << v8 << std::endl;
            }

            std::cout << v1 << v2 << v3 << v6 << v7 << std::endl;
        }

        std::cout << v1 << v2 << v3 << v6 << std::endl;
    }

    std::cout << v1 << std::endl;

    int v9{9};

    std::cout << v1 << v9 << std::endl;

    return 0;
}