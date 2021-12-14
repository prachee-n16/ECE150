// Identify compiler errors
#include <iostream> //no space in iostream
#include <cmath>

int main(); // main can not return int
// 2 functions with the same name
bool done_assignment(int assignment_number1);
bool done_assignment2(int assignment_number2);

bool done_assignment(int assignment_number1)
{
    return true;
}

bool done_assignment2(int assignment_number2)
{
    return true;
}

int main()
{
    done_assignment((2));
    return 0;
}