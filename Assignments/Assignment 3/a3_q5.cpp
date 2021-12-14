#include <iostream>

int main();
int quadrant(double x, double y);

int quadrant(double x, double y)
{
    if ((x == 0) || (y == 0))
    {
        return 0;
    }
    else if (x > 0)
    {
        if (y > 0)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        if (y > 0)
        {
            return 4;
        }
        else
        {
            return 3;
        }
    }
}
int main()
{
}
