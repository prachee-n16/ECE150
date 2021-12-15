// Write a program that asks the user to enter a number.
// or the number entered by the user, create a dynamically allocated array of integers.
// Populate the array

// Print to the console the contents of the dynamically allocated array.  Ensure that you also
// deallocate the dynamically allocated array before terminating the program.

#include <iostream>

int main();
int main()
{
    int n{};
    std::cout << "Enter size of array:" << std::endl;
    std::cin >> n;

    std::size_t s = n;
    int *arr{new int[s]};
    for (int i = 0; i++; i < s)
    {
        arr[i] = i;
    }

    delete arr;
    arr = nullptr;
}