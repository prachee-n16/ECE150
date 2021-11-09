#include <iostream>

int main();

int main()
{
    double x(0.0);

    std::cout << "Enter value of x:";
    std::cin >> x;

    //This local variable should hold the result of stair(x)
    int stair_result{};

    //TASK: write code that calculates an integer value
    //corresponding to the value of the function stair(x) here

    if (x > 0)
    {
        int n = 1;
        while (n <= x + 1)
        {
            if (n <= x)
            {
                stair_result = n;
            }
            n = n + 1;
        }
    }

    if (x < 0)
    {
        int m = 0;
        while (m >= x - 1)
        {
            if (m < x && m != x)
            {
                stair_result = m;
            }
            if (m == x)
            {
                stair_result = m;
                m = m - 1;
            }
            m = m - 1;
        }
    }
    std::cout << "The value of stair(x) is: " << stair_result << std::endl;

    return 0;
}