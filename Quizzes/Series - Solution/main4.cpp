#include "TaylorSeries.hpp"
#include "GeometricSeries.cpp"
#include "ExponentialSeries.cpp"
#include "TrigonometricSeries.cpp"
#include <iostream>
#ifndef MARMOSET_TESTING
int main();
#endif

// Derived class declarations here

#ifndef MARMOSET_TESTING
int main()
{
    GeometricSeries gser{10};
    std::cout << gser.calculate_function(0.253) << std::endl;

    ExponentialSeries eser{10};
    std::cout << eser.calculate_function(12.32) << std::endl;

    TrigonometricSeries tser{10};
    std::cout << tser.calculate_function(3.1415) << std::endl;

    return 0;
}
#endif