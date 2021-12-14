// No loop constructs, only local variables
// Find mean, median of four numbers

#include <iostream>

int main();
double mean(double a, double b, double c, double d);
double median(double a, double b, double c, double d);

int main()
{
    mean(3, 4, 5, 6);
    median(3, 4, 5, 6);
    return 0;
}

double mean(double a, double b, double c, double d)
{
    double mean = 0.0;
    mean = (a + b + c + d) / 4;
    return mean;
}
double median(double a, double b, double c, double d)
{
    double median = 0.0;
    double arr[4] = {a, b, c, d};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    median = (arr[1] + arr[2]) / 2;
    return median;
}
