#include <iostream>
#include <cmath>
#include <stdexcept>
#include "TaylorSeries.hpp"

class ExponentialSeries : public TaylorSeries
{
public:
    ExponentialSeries(std::size_t precision);

private:
    double get_term_value(double x_value, std::size_t idx) const;
};

ExponentialSeries::ExponentialSeries(std::size_t precision)
{
    set_precision(precision);
}

double ExponentialSeries::get_term_value(double x_value, std::size_t idx) const
{
    return pow(x_value, idx) / tgamma(idx + 1);
}