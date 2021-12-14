#include <iostream>
#include <cmath>

// Function declarations
int main();
double my_abs(double x);

// Function definitions
int main()
{
    double x{};
    std::cout << "Enter a number: ";
    std::cin >> x;

    std::cout << "Our absolute value function"
              << std::endl;
    std::cout << "     my_abs(" << x << ") = "
              << my_abs(x) << std::endl;

    std::cout << "The standard library's absolute value "
              << "function" << std::endl;
    std::cout << "   std::abs(" << x << ") = "
              << std::abs(x) << std::endl;

    return 0;
}

// double my_abs( ... )
//
// @author    Douglas Wilhelm Harder
// @date      2020-09-09
// @version   1.0
//
// @param x    a real number
//
// @returns    the absolute value of 'x'
//
// @algorithm
// If 'x < 0', '-x' is returned;
//  otherwise,  'x' is returned.
//
// Exercises:
//   1. Explain why the following would not work:
//
//   Result is never initialized as it doesn't acc
//   go through the if loops during compiling
//          double my_abs( double x ) {
//           	if ( x >= 0 ) {
//          	  double result{ x };
//          	} else {
//              double result{ -x };
//            }
//
//            return result;
//          }
//
//   2. For the following implementations, will 'fail'
//      ever be printed to the screen? Why or why not?
//
//          double my_abs( double x ) {
//          	double result{};
//
//           	if ( x >= 0 ) {
//          	  result = x;
//          	} else {
//              result = -x;
//            }
//
//            return result;
//            std::cout << "fail" << std::endl;
//            No because it breaks from the function after returning result
//          }
//
//          double my_abs( double x ) {
//           	if ( x >= 0 ) {
//          	  return  x;
//          	} else {
//              return -x;
//            }
//
//              No since the loop will break before it goes down.
//              std::cout << "fail" << std::endl;
//          }

double my_abs(double x)
{
    double result{};

    if (x >= 0)
    {
        result = x;
    }
    else
    {
        result = -x;
    }

    return result;
}