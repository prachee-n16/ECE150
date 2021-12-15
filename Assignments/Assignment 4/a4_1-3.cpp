// Write a C++ statement that declares an
// array of integers that can hold ten integers
#include <iostream>
int main();

int main()
{
    int arr[10]{}; // Array can hold 10 integers
    return 0;

    std::cout << arr[11] << std::endl;
}

// Explain the different between
//  (1) pass-by-value
//  When a variable is used as a argument for the function, it doesn't
//  update the value of it inside the function
//  (2) pass-by-reference
//  Pointer to a variable is passed as an argument for the function
//  which allows the function to update it's value