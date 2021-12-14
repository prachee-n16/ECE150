#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cassert>

// Let ax^2+bx+c be a polynomial
// Print both roots of this polynomial as complex numbers

int main();
void print_roots(double a, double b, double c);

void print_roots(double a, double b, double c)
{

    double d = std::sqrt((b * b) - (4 * a * c));
    double root1 = (-b + d) / (2 * a);
    double root2 = (-b - d) / (2 * a);
    std::cout << "x = " << root1 << " and x = "
              << root2;
}

int main()
{
    print_roots(1, 3, 2);
    return 0;
}