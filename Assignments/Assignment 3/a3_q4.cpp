// flip-four-digit-number

#include <iostream>

int main();
int main()
{
    int num = -2545;
    bool neg = false;
    int rev_num = 0;

    if (num < 0)
    {
        neg = true;
        num = -num;
    }

    for (int i = 0; i < 4; i++)
    {
        int digit = num % 10;
        rev_num = rev_num * 10 + digit;
        num /= 10;
    }

    if (neg == true)
    {
        rev_num = -rev_num;
    }

    std::cout << rev_num;
}