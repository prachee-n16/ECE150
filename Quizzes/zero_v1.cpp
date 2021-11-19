#include <iostream>
#include <cmath>

// Function declaration below:
// TODO
//

// Only modify main's definition for your own testing
// Do not touch the preprocessor directives (#ifndef .. #endif)

#ifndef MARMOSET_TESTING
// Do not modify!
int main();
double find_zero(double initial_value, double step_size);
#endif

// Function definition below:
// TODO
//
//
//

double find_zero(double num, double step)
{
    bool isPositive{};

    if (std::cos(std::sqrt(num)) > 0)
    {
        bool isPositive = true;
    }

    if (std::cos(std::sqrt(num)) < 0)
    {
        bool isPositive = false;
    }

    if (std::cos(std::sqrt(num)) == 0)
    {
        return num;
    }

    for (int i = 0; i < 10; i++)
    {
        double f_x = std::cos(std::sqrt(num));

        std::cout << "f(" << num << ")"
                  << " = " << f_x << std::endl;

        if ((std::cos(std::sqrt(num)) < 0) && (isPositive == true))
        {
            step = step / 10;
            step = step * -1;
            isPositive = false;
        }
        if ((std::cos(std::sqrt(num)) > 0) && (isPositive == false))
        {
            step = step / 10;
            step = step * -1;
            isPositive = true;
        }

        if (std::cos(std::sqrt(num)) == 0)
        {
            std::cout << num;
            break;
        }
        num = num + step;
    }
    //ADD LINE HERE

    return 0;
}

#ifndef MARMOSET_TESTING
int main()
{
    // Modify here for testing purposes
    find_zero(0.0, 1.0);

    return 0;
}
#endif
