#include <cassert>
#include <iomanip>
#include <iostream>
#include <math.h>

// 1. Implement a program that computes the determinant of a 2x2 matrix
// with the following form
//  a b
//  c d
// where determinant = ad - bc.
// Matrix is not invertible if determinant is 0.
// a, b, c and d are doubles: must be provided as user input to the program
void findDeterminant(int determinant_int);
void findDeterminant(int determinant_int)
{
    double a, b, c, d{0.0};
    std::cout << "Enter matrix in form: \na b \nc d" << std::endl;
    std::cin >> a >> b >> c >> d;

    double determinant = a * d - b * c;
    std::cout << "The determinant of the matrix is: " << determinant << std::endl;
    if (determinant == 0)
    {
        std::cout << "Matrix is not invertible.";
    }
}

// 2. For a 2x2 matrix as input, print to console the result.
void matrixMultiplication();
void matrixMultiplication()
{
    double a, b, c, d{0.0};
    double e, f, g, h{0.0};

    std::cout << "Enter Matrix 1" << std::endl;
    std::cin >> a >> b >> c >> d;
    std::cout << "Enter Matrix 2" << std::endl;
    std::cin >> e >> f >> g >> h;

    double m_1_1 = a * e + b * g;
    double m_1_2 = a * f + b * h;
    double m_2_1 = c * e + d * g;
    double m_2_2 = c * f + d * h;
    std::cout << "Resulting Matrix" << std::endl;
    std::cout << m_1_1 << " " << m_1_2 << " " << m_2_1 << " " << m_2_2 << " " << std::endl;
}

// 3. Implement a program that asks the user to input a character, and prints
//  to the console whether it is a consonant, vowel, digit or symbol
void checkSymbol()
{
    char s{};
    std::cout << "Enter a character: " << std::endl;
    std::cin >> s;

    if ((s == 'a') || (s == 'e') || (s == 'i') || (s == 'o') || (s == 'u'))
    {
        std::cout << "It is a vowel." << std::endl;
    }
    else if (!isalpha(s))
    {
        std::cout << "It is a number." << std::endl;
    }
    else
    {
        std::cout << "It is a consonant" << std::endl;
    }
}

// Ask user for four double numbers and then print the max, min of them
void find_min_max()
{
    double a, b, c, d{0.0};
    std::cout << "Enter four numbers: " << std::endl;
    std::cin >> a;

    double min = a;
    double max = a;

    std::cin >> b;
    if (b < min)
    {
        b = min;
    }
    if (b > max)
    {
        b = max;
    }

    std::cin >> c;
    if (c < min)
    {
        c = min;
    }
    if (c > max)
    {
        c = max;
    }

    std::cin >> d;
    if (d < min)
    {
        d = min;
    }
    if (d > max)
    {
        d = max;
    }

    std::cout << "The minimum of all four numbers is: " << min;
    std::cout << "The maximum of all four numbers is: " << max;
}

int main();

int main()
{
    findDeterminant(((((0)))));
    // matrixMultiplication();
    // checkSymbol();

    return 0;
}