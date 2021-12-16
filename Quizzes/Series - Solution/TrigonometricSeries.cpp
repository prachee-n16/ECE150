#include <iostream>
#include <cmath>
#include <stdexcept>
#include "TaylorSeries.hpp"

class TrigonometricSeries : public TaylorSeries
{
public:
    TrigonometricSeries(std::size_t precision);

private:
    double get_term_value(double x_value, std::size_t idx) const;
};

TrigonometricSeries::TrigonometricSeries(std::size_t precision)
{
    set_precision(precision);
}

double TrigonometricSeries::get_term_value(double x_value, std::size_t idx) const
{
    return pow(-1.0, idx) * pow(x_value, 2.0 * idx) / tgamma(2.0 * idx + 1);
}