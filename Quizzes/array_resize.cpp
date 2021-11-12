#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif
int *add_element(int *array, std::size_t &capacity, int value_to_add);
int *remove_element(int *array, std::size_t &capacity, int value_to_remove);

int *add_element(int *array, std::size_t &capacity, int value_to_add)
{
    capacity++;
    int *temp = new int[capacity]{};

    int counter = 0;
    for (int i = 0; i < capacity; i++)
    {
        if ((value_to_add <= array[i]) && (value_to_add >= array[i - 1]))
        {
            temp[i] = value_to_add;
        }
        else
        {
            temp[i] = array[counter];
            counter++;
        }
        std::cout << temp[i] << " and counter " << counter - 1 << " and i " << i << std::endl;
    }
    delete[] array;
    array = nullptr;
    return temp;
}

int *remove_element(int *array, std::size_t *capacity, int value_to_remove)
{
    capacity--;
    int *temp = new int[capacity]{};
    int counter = 0;
    bool found = false;
    for (int i = 0; i < capacity; i++)
    {
        if ((value_to_remove == array[i]) && (found == false))
        {
            found = true;
        }
        else
        {
            temp[counter] = array[i];
            counter++;
        }
        std::cout << temp[i];
    }

    delete[] array;
    array = nullptr;

    return temp;
}

#ifndef MARMOSET_TESTING
int main()
{
    std::size_t capacity = 5;
    int array[capacity]{2, 5, 6, 20, 24};
    remove_element(array, capacity, 6);
    return 0;
}
#endif