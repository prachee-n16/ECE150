#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif

std::size_t partition(double array[], std::size_t cap, double val);

// NO DUPLICATES, SORTED IN ASCENDING
// ASSUME ARR_SIZE <= 1 ELEMS

// RETURN INDEX K WHERE
// LEFT ARRAY HAS VALUES LESS THAN OR EQUAL TO VAL
// RIGHT ARRAY HAS VALUES GREATER THEN VAL

std::size_t partition(double array[], std::size_t cap, double val)
{
    // code special case
    if (val < array[0])
    {
        return 0;
    }
    else if (val > array[cap - 1])
    {
        return cap;
    }
    else
    {
        for (int k = 0; k < cap; k++)
        {
            if ((k + 1) < cap)
            {
                if ((array[k] < val) && (array[k + 1] > val))
                {
                    return k;
                }
            }
            else
            {
                if ((array[k] == val))
                {
                    return k;
                }
                else if (array[k] < val)
                {
                    return k + 1;
                }
            }
        }
    }
    return 0;
}

#ifndef MARMOSET_TESTING
int main()
{
    const std::size_t CAP{10};
    double array[CAP]{-7.9, -6.1, -4.1, -0.3, 2.9, 5.1, 5.3, 6.7, 6.9, 7.0};
    std::cout << partition(array, CAP, 7.0) << std::endl;
    //  val = 5.0, function should return 1, for index 1
    std::cout << partition(array, CAP, 0.2) << std::endl;
    //  val = 0.2, function should return 0
    std::cout << partition(array, CAP, 10.4) << std::endl;
    //  val = 10.4, function should return 5
    return 0;
}
#endif