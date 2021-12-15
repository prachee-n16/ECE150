// Write a function that performs 2s complements
// on an array of boolean that can hold 32 values.

#include <iostream>
// Slightly incorrect implementation

int main();
void twos_complement(bool arr[32]);

void twos_complement(bool arr[4])
{
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = 1;
        }
        else if (arr[i] == 1)
        {
            arr[i] = 0;
        }

        if (i == 3)
        {
            arr[3] = 1;
        }
    }

    // prints the number
    for (int i = 0; i < 4; i++)
    {
        std::cout << arr[i];
    }
}

int main()
{
    bool arr[4]{0, 1, 0, 1};
    twos_complement(arr);
}