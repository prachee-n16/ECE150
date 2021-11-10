#include <iostream>

int main();
//Algorithms and Templates

//Introduction to algorithms
//What is an algorithm?
//sequence of instructions that solves a specific problem
//Algorithms seen in elementary and secondary school (check prime, divisibility etc.)
//Solve following problems for arrays:
//searching an array (unsorted and sorted),
//determine if array is sorted and then,
//sort array
//Additional:
//Recursive Algorithms

//Searching an array
//Suppose we want to determine if an array contains some value
bool find_v1(double const value, double const array[], std::size_t const capacity);
//Why use const --> we are not changing their values

bool find_v1(double const value, double const array[], std::size_t const capacity)
{
    //Iterate through the array (known as a linear search)
    for (std::size_t k{0}; k < capacity; ++k)
    {
        //Check if the entry = value we are searching for
        if (array[k] == value)
        {
            return true;
        }
    }
    //For loop finishes means none of the entries are the value we
    //are looking for
    return false;

    //How useful is this response?
    //Returning true is pointless cause we don't know where it is?
    //Possible improv: Pass a local var by ref, and when value is found return index.
    //Even better improv: Return value of an index between 0 and capacity - 1
    //When value not found, return capacity
}

std::size_t find_v2(double const array[], std::size_t const capacity, double const value);
std::size_t find_v2(double const array[], std::size_t const capacity, double const value)
{
    for (std::size_t k{0}; k < capacity; ++k)
    {
        if (array[k] == value)
        {
            return k;
        }
    }
    return capacity;
}

int main()
{
    const std::size_t CAPACITY{10};
    double data[CAPACITY]{1, 2, 3, 4, 5, 6, 7, 8, 100, 0};

    std::size_t index{find_v2(data, CAPACITY, 100.0)};

    if (index == CAPACITY)
    {
        //std::cout << "Doesn't contain number!" << std::endl;
    }
    else
    {
        //std::cout << "The array contains number at index " << index << std::endl;
    }
    return 0;

    //Why declare parameters to be const?
    //Don't want to mess with something when we run an incorrect statement.
}