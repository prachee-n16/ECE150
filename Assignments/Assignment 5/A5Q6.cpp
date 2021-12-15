#include <iostream>

bool is_palindrome(char *a_first, char *a_last);
int main();

bool is_palindrome(char *a_first, char *a_last)
{
    if (*a_first == *a_last)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    char str[26]{"Hello! Am I a palindrome?"};
    if (is_palindrome(str, &str[25]))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    return 0;
}