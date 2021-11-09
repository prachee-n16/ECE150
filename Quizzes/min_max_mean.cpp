#include <iostream>

int main();

int main()
{
    int quantity{};
    std::cin >> quantity;
    int min{};
    int max{};
    for (int i = 0; i < quantity; i++)
    {
        int x{};
        std::cin >> x;
        if (min > x)
        {
            min = x;
        }
        if (max < x)
        {
            max = x;
        }
    }
    std::cout << min << " " << max << std::endl;

    return 0;
};