#include <iostream>

int main();
double areaTrapezoid(double x1, double y1, double x2, double y2);
double addArea(double sumAreas, double area);

int main()
{
    int n{};
    double x1{};
    double y1{};
    double x2{};
    double y2{};

    double sumAreas{};
    std::cout << "Enter the number of trapezoids:";
    std::cin >> n;

    while (n != 0)
    {
        std::cout << "Enter the x y coordinates:";
        std::cin >> x1 >> y1;

        for (int i{0}; i < n; ++i)
        {
            std::cin >> x2;
            std::cin >> y2;
            double area1 = areaTrapezoid(x1, y1, x2, y2);
            sumAreas = addArea(sumAreas, area1);
            x1 = x2;
            y1 = y2;
        }
        std::cout << "The area the trapezoids take up is: " << sumAreas << std::endl;
        std::cout << "Enter the number of trapezoids:";
        std::cin >> n;

        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
        sumAreas = 0;
    }

    std::cout << "Program terminated";

    return 0;
}

double areaTrapezoid(double x1, double y1, double x2, double y2)
{
    double a = y1;
    double b = y2;
    double h = x2 - x1;

    double areaoftrapezoid = ((a + b) / 2) * h;

    return areaoftrapezoid;
}

double addArea(double sumAreas, double area)
{
    sumAreas += area;
    return sumAreas;
}
