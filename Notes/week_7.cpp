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

//Sorting an array
//Each entry is greater than or equal to all previous entries is a sorted array
bool is_sorted_v1(double const array[], std::size_t const capacity);
bool is_sorted_v1(double const array[], std::size_t const capacity)
{
    //When comparing entries, you are comparing
    //array[0] <= array[1] ... array[8] < array[9] for array of 10 elements

    for (std::size_t k{0}; k < capacity - 1; ++k)
    {
        //check if next entry is greater then previous entry
        if (array[k] > array[k + 1])
        {
            return false;
        }
        //when we have checked all pairs
    }
    return true;

    //How useful is the response?
    //Know where the out of entry is probably.
}

std::size_t is_sorted_v2(double const array[], std::size_t const capacity);
std::size_t is_sorted_v2(double const array[], std::size_t const capacity)
{
    for (std::size_t k{0}; k < capacity - 1; ++k)
    {
        if (array[k] > array[k + 1])
        {
            return k + 1;
        }
    }
    return capacity;

    //Introducing errors
    //Imagine for loop said k < capacity. Then, the following comparision:
    //array[capacity - 1] > array [capacity]
    //Gives wrong answer cause when it looks at next address, it blindly takes that value
}

int main()
{
    const std::size_t CAPACITY{10};
    double data[CAPACITY]{1, 2, 3, 4, 5, 6, 7, 8, 100, 0};

    std::size_t index{find_v2(data, CAPACITY, 100.0)};

    //Why declare parameters to be const?
    //Don't want to mess with something when we run an incorrect statement.
}