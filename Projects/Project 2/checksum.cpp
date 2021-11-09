#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
unsigned int add_checksum(unsigned int n);
void add_checksum(unsigned int array[], std::size_t capacity);
bool verify_checksum(unsigned int n);
unsigned int remove_checksum(unsigned int n);
void remove_checksum(unsigned int array[], std::size_t capacity);
#endif

#ifndef MARMOSET_TESTING
int main()
{
    unsigned int value_to_protect{0};
    unsigned int protected_value = add_checksum(value_to_protect);
    std::cout << "The value " << value_to_protect
              << " with the checksum added is " << protected_value
              << "." << std::endl;

    if (verify_checksum(protected_value))
    {
        std::cout << "The checksum is valid." << std::endl;
    }
    else
    {
        std::cout << "The checksum is invalid." << std::endl;
    }
    const std::size_t QTY_VALUES{3};
    unsigned int value_series[QTY_VALUES]{20201122, 20209913, 20224012};

    add_checksum(value_series, QTY_VALUES);

    std::cout << "Series with checksums added: ";
    for (std::size_t series_index{0};
         series_index < QTY_VALUES; series_index++)
    {
        std::cout << value_series[series_index] << "";
    }

    std::cout << std::endl;
    return 0;
}
#endif

unsigned int add_checksum(unsigned int n)
{
    int num = n;
    int digit = 0;   //digit in the number
    int d = 0;       //checksum output
    int counter = 0; //counter
    int sum = 0;

    if (n > 99999999)
    {
        n = UINT_MAX;
        return n;
    }

    while (n != 0)
    {
        digit = n % 10;
        n = n / 10;
        if (counter % 2 == 0)
        {
            digit = digit * 2;
        }
        if (digit > 9)
        {
            int temp = digit;
            int n = 0;
            digit = 0;
            while (temp != 0)
            {
                n = temp % 10;
                temp = temp / 10;
                digit = digit + n;
            }
        }
        sum = sum + digit;
        counter++;
    }
    d = (sum * 9) % 10;
    return num * 10 + d;
}

void add_checksum(unsigned int array[], std::size_t capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        array[i] = add_checksum(array[i]);
    }
}

bool verify_checksum(unsigned int n)
{
    if (n > 999999999)
    {
        return false;
    }
    bool is_checksum = false;
    int num = n / 10;

    if (add_checksum(num) == n)
    {
        is_checksum = true;
    }

    return is_checksum;
}

unsigned int remove_checksum(unsigned int n)
{
    int d = n % 10;   //stores checksum of number
    int num = n / 10; //stores number without checksum
    int d_check = add_checksum(num) % 10;

    if (num > 99999999)
    {
        return UINT_MAX;
    }

    if (d == d_check)
    {
        n = num;
    }
    else
    {
        n = UINT_MAX;
    }

    return n;
}

void remove_checksum(unsigned int array[], std::size_t capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        array[i] = remove_checksum(array[i]);
    }
}