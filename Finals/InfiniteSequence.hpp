#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <cstdlib>

class InfiniteSequence
{
protected:
    double *values;
    std::size_t qty_relevant_values;

public:
    InfiniteSequence();
    ~InfiniteSequence();
    double operator[](unsigned int idx) const;
};

#endif