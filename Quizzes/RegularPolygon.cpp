#include <iostream>
#include <cmath>

class RegularPolygon
{
public:
    //Constructor
    RegularPolygon(int num_sides, double length);
    int get_qty_sides() const;
    double get_side_length() const;
    double get_area() const;
    bool operator<(RegularPolygon const &other) const;

private:
    int side{};
    double length{};
};

RegularPolygon::RegularPolygon(int num_sides, double length)
{
    if (num_sides <= 0)
    {
        this->side = 3;
        this->length = 1;
    }
    else
    {
        this->side = num_sides;
        this->length = length;
    }
}

int RegularPolygon::get_qty_sides() const { return side; }

double RegularPolygon::get_side_length() const { return length; }

double RegularPolygon::get_area() const
{
    double p = (side * length) / 2;
    double a = ((length) / (2 * tan((180 / side) * (3.14159 / 180))));
    return p * a;
}

bool RegularPolygon::operator<(RegularPolygon const &other) const
{
    double p = (side * length) / 2;
    double a = ((length) / (2 * tan((180 / side) * (3.14159 / 180))));
    double area = p * a;
    double other_area = other.get_area();

    if ((area) < (other_area))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main()
{
    RegularPolygon polygon1(8, 8.07);
    std::cout << polygon1.get_area() << std::endl;
    return 0;
}
#endif