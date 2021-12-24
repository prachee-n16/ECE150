#include <iostream>
#include "InfiniteSequence.hpp"

InfiniteSequence::InfiniteSequence()
{
    values = nullptr;
    qty_relevant_values = 0;
}

InfiniteSequence::~InfiniteSequence()
{
    if (values != nullptr)
    {
        delete[] values;
        values = nullptr;
    }
}