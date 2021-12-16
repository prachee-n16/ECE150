#ifndef SERIES_HPP
#define SERIES_HPP

#include <cstdlib>

class TaylorSeries
{
    protected:
        std::size_t precision;
    private:
        virtual double get_term_value(double x_value, std::size_t idx) const = 0;
    public :
        TaylorSeries();
        TaylorSeries(std::size_t precision);
        double calculate_function(double x_value) const;
        void set_precision(std::size_t precision);
};
#endif