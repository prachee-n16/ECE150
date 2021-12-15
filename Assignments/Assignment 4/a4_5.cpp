#include <iostream>

// Write a function that takes an unsigned integer, an array of Boolean values
// and its capacity and represents bit values from array of boolean values

// assume bit_data[0] is least significant and largest index is most significant
//  2668983664 --> 1 001111100010101011101010111000 0

int main();
void bits_as_array(unsigned int n, bool arr[], std::size_t s);

void bits_as_array(unsigned int n, bool arr[], std::size_t s)
{
    for (int i = 0; i < s; i++)
    {
        arr[i] = n % 2;
        n = n / 2;
    }

    for (int i = 0; i < s; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

int main()
{
    bool arr[20]{};
    bits_as_array(29, arr, 20);
    return 0;
}