#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif
int *remove_elements(int *&original_array, std::size_t original_capacity, int *&remove_array, std::size_t remove_capacity);

int *remove_elements(int *&original_array, std::size_t original_capacity, int *&remove_array, std::size_t remove_capacity)
{
    std::size_t output_capacity = original_capacity - remove_capacity;
    int *output_array = new int[output_capacity];
    int k = 0;

    for (int i{0}; i < original_capacity; i++)
    {
        bool to_be_removed = false;
        for (int j{0}; j < remove_capacity; j++)
        {
            if (remove_array[j] == original_array[i])
            {
                to_be_removed = true;
            }
        }
        if (to_be_removed)
        {
            to_be_removed = false;
        }
        else
        {
            output_array[k] = original_array[i];
            k++;
        }
    }

    delete[] original_array;
    delete[] remove_array;

    original_array = nullptr;
    remove_array = nullptr;
    return output_array;
}
#ifndef MARMOSET_TESTING
int main()
{
    std::size_t original_capacity = 7;
    std::size_t remove_capacity = 3;

    int *original_array = new int[original_capacity]{1, 3, 4, 5, 7, 11, 22};
    int *remove_array = new int[remove_capacity]{1, 3, 22};

    remove_elements(original_array, original_capacity, remove_array, remove_capacity);
}
#endif