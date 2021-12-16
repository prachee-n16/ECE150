#include <iostream>
#include <cmath>
#include <stdexcept>
#include "TaylorSeries.hpp"

class GeometricSeries : public TaylorSeries
{
public:
    GeometricSeries(std::size_t precision);
    double calculate_function(double x_value) const;

private:
    double get_term_value(double x_value, std::size_t idx) const;
};

GeometricSeries::GeometricSeries(std::size_t precision)
{
    set_precision(precision);
}
double GeometricSeries::calculate_function(double x_value) const
{
    if (x_value <= -1 || x_value >= 1)
    {
        throw std::logic_error("The x_value is out of range");
    }
    double sum{};
    for (int i{}; i < this->precision; i++)
    {
        sum += get_term_value(x_value, i);
    }
    return sum;
}
double GeometricSeries::get_term_value(double x_value, std::size_t idx) const
{
    return pow(x_value, idx);
}