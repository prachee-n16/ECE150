#include <iostream>
#include <math.h>
// need to revisit this in the end?

int main();
int bin_to_decimal(bool bit_data[32]);

int bin_to_decimal(bool bit_data[32])
{
    int num{};
    for (int i = 0; i < 32; i++)
    {
        num += bit_data[i] * pow(2, i);
        std::cout << num << std::endl;
    }
    return num;
}

int main()
{
    bool res[32]{0, 0, 0, 0,
                 0, 0, 0, 0,
                 0, 0, 0, 0,
                 0, 0, 0, 0,
                 0, 0, 0, 0,
                 0, 0, 0, 0,
                 1, 0, 0, 1,
                 1, 0, 1, 1};
    bin_to_decimal(res);

    return 0;
}