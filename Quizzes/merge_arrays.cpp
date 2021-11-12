#include <iostream>

//merges two arrays into one array while maintaining order.
#ifndef MARMOSET_TESTING
int main();
void insert(int *&array, std::size_t const i);
#endif
int *merge_arrays(int *&data_1, std::size_t data_1_size, int *&data_2, std::size_t data_2_size);

int *merge_arrays(int *&data_1, std::size_t data_1_size, int *&data_2, std::size_t data_2_size)
{
    std::size_t data_3_size = data_1_size + data_2_size;
    int *data_3 = new int[data_3_size]{};
    int temp3 = data_3_size;
    int temp1 = data_1_size;
    int temp2 = data_2_size;

    while (temp3 != 0)
    {
        while (temp1 != 0)
        {
            data_3[temp3 - 1] = data_1[temp1 - 1];
            temp1--;
            temp3--;
        }
        while (temp2 != 0)
        {
            data_3[temp3 - 1] = data_2[temp2 - 1];
            temp2--;
            temp3--;
        }
    }

    //SORTING ALGO.
    for (std::size_t i{2}; i <= data_3_size; ++i)
    {
        insert(data_3, i);
    }

    for (std::size_t i{0}; i < data_3_size; ++i)
    {
        std::cout << data_3[i] << " ";
    }

    delete data_1;
    delete data_2;

    data_1 = nullptr;
    data_2 = nullptr;

    return data_3;
}

#ifndef MARMOSET_TESTING
void insert(int *&array, std::size_t const i)
{
    int value{array[i - 1]};

    std::size_t k{};

    for (k = i - 1;
         (k > 0) && (array[k - 1] > value); --k)
    {
        array[k] = array[k - 1];
    }

    array[k] = value;
}

int main()
{
    std::size_t data_1_size = 5;
    std::size_t data_2_size = 7;

    int *data_1 = new int[data_1_size]{2, 3, 3, 5, 8};
    int *data_2 = new int[data_2_size]{3, 4, 5, 6, 7, 8, 9};

    merge_arrays(data_1, data_1_size, data_2, data_2_size);
    //expected to result in 2,3,3,3,4,5,5,6,7,8,8,9
    return 0;
}
#endif