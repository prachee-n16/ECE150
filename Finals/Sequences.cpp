#include "InfiniteSequence.hpp" // This imports the parent class

#include <iostream>
#include <cmath>

#ifndef MARMOSET_TESTING
int main();
#endif

// Derived class declarations here
class EventuallyZeroInfSeq : public InfiniteSequence
{
protected:
    EventuallyZeroInfSeq(std::size_t qty_relevant_values);
    EventuallyZeroInfSeq(double *values);

public:
    EventuallyZeroInfSeq(double array[], std::size_t capacity);
    double operator[](unsigned int idx) const;
};

EventuallyZeroInfSeq::EventuallyZeroInfSeq(double array[], std::size_t capacity)
{
    values = array;
    qty_relevant_values = capacity;
}

double EventuallyZeroInfSeq::operator[](unsigned int idx) const
{
    return values[idx];
}

class PeriodicInfSeq : public InfiniteSequence
{
protected:
    PeriodicInfSeq(std::size_t qty_relevant_values);
    PeriodicInfSeq(double *values);

public:
    PeriodicInfSeq(double array[], std::size_t capacity);
    double operator[](unsigned int idx) const;
};

PeriodicInfSeq::PeriodicInfSeq(double array[], std::size_t capacity)
{
    values = array;
    qty_relevant_values = capacity;
}

double PeriodicInfSeq::operator[](unsigned int idx) const
{
    return values[idx];
}

class GeometricInfSeq : public InfiniteSequence
{
protected:
    GeometricInfSeq(std::size_t qty_relevant_values);
    GeometricInfSeq(double *values);

public:
    GeometricInfSeq(double a, double r);
    double operator[](unsigned int idx) const;
};

GeometricInfSeq::GeometricInfSeq(double a, double r)
{
    values[0] = a;
    qty_relevant_values = r;
}

double GeometricInfSeq::operator[](unsigned int idx) const
{
    values[idx] = values[0] * pow(qty_relevant_values, idx);
    return values[idx];
}

#ifndef MARMOSET_TESTING
int main()
{
    double arr[5] = {1, 2, 3, 4, 5};
    EventuallyZeroInfSeq zseq{arr, 5};
    std::cout << zseq[1] << std::endl;
    std::cout << zseq[7] << std::endl;

    PeriodicInfSeq pseq{arr, 5};
    std::cout << pseq[1] << std::endl;
    std::cout << pseq[7] << std::endl;

    GeometricInfSeq gseq{5, 3};
    std::cout << gseq[0] << std::endl;
    std::cout << gseq[5] << std::endl;

    return 0;
}
#endif

// Derived class member function definitions here