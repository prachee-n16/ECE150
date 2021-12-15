#include <iostream>
bool is_palindrome(char data[], std::size_t capacity);
int main();

bool is_palindrome(char data[], std::size_t capacity)
{

    return true;
}

int main()
{
    char palindrome[4] = {'a', 'b', 'b', 'a'};
    std::cout << is_palindrome(palindrome, 4);
    return 0;
}