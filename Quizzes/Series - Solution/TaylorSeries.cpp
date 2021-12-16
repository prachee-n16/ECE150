#include <iostream>
#include <cmath>
#include <stdexcept>

#include "TaylorSeries.hpp"

TaylorSeries::TaylorSeries()
{
    this->set_precision(5);
}
TaylorSeries::TaylorSeries(std::size_t precision)
{
    this->set_precision(precision);
}

double TaylorSeries::calculate_function(double x_value) const
{
    double sum{};
    for (int i{}; i < this->precision; i++)
    {
        sum += get_term_value(x_value, i);
    }
    return sum;
}

void TaylorSeries::set_precision(std::size_t precision)
{
    if (precision < 5 || precision > 100)
    {
        throw std::logic_error("The precision specified is unneeded");
    }

    this->precision = precision;
}