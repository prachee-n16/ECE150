#include <iostream>
int main();

int main()
{
    int m = 100;
    int n = 3000;
    if ((5 * m + 3 * n <= 10000) && (m <= 1100) && (4 * m + n <= 5000) && (8 * m + 17 * n <= 50000) && (m >= 0) && (n >= 0))
    {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    return 0;
}