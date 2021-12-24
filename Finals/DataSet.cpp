#include <iostream>
#include <cmath>
#include <stdexcept>

#ifndef MARMOSET_TESTING
int main();
#endif

class DataSet
{
public:
    DataSet();
    ~DataSet();
    void add_data_element(double n);
    double mean() const;
    double std_dev() const;

protected:
    double sum_of_values;
    double sum_of_squares;
    int qty_values;
};

DataSet::DataSet()
{
    sum_of_values = 0;
    sum_of_squares = 0;
    qty_values = 0;
};

DataSet::~DataSet(){};

void DataSet::add_data_element(double n)
{
    qty_values++;
    sum_of_squares += (n * n);
    sum_of_values += n;
}

double DataSet::mean() const
{
    if (qty_values == 0)
    {
        throw std::logic_error("No values have been entered yet");
    }
    else
    {
        double mean{};
        mean = sum_of_values / qty_values;
        return mean;
    }
}
double DataSet::std_dev() const
{
    if (qty_values == 0)
    {
        throw std::logic_error("No values have been entered yet");
    }
    else
    {
        double std_dev{};
        std_dev = sqrt((sum_of_squares / qty_values) - (pow((sum_of_values / qty_values), 2)));
        return std_dev;
    }
}

#ifndef MARMOSET_TESTING
int main()
{
    DataSet data{};
    data.add_data_element(3.2);
    std::cout << data.mean() << std::endl;    // prints 3.2
    std::cout << data.std_dev() << std::endl; // prints 0
    data.add_data_element(5.6);
    data.add_data_element(2.9);
    // The mean and the std_deviation of the three values 3.2, 5.6, and 2.9
    std::cout << data.mean() << std::endl;    // prints 3.9
    std::cout << data.std_dev() << std::endl; // prints 1.2083
    data.add_data_element(4.1);
    data.add_data_element(7.8);
    // The mean and std_deviation of the five values 3.2, 5.6, 2.9, 4.1 and 7.8
    std::cout << data.mean() << std::endl;    // prints 4.72
    std::cout << data.std_dev() << std::endl; // prints 1.8038
    return 0;
}
#endif