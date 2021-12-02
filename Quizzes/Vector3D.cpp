#include <iostream>
#include <cmath>
#include <stdexcept>

// Expect you guys to all have this

class Vector3D
{
public:
    Vector3D(double x, double y, double z);
    double *get_values() const;
    void set_values(double x_1, double y_1, double z_1);
    double get_magnitude() const;
    Vector3D cross_product(Vector3D const &other) const;
    bool operator<(Vector3D const &other) const;
    double operator*(Vector3D const &other) const;
    Vector3D operator+(Vector3D const &other) const;
    Vector3D operator-(Vector3D const &other) const;
    ~Vector3D();

private:
    double x;
    double y;
    double z;
};

Vector3D::Vector3D(double x, double y, double z)
{
    if (std::isnan(x) || std::isnan(y) || std::isnan(z))
    {
        throw std::invalid_argument("Invalid Argument");
    }
    this->x = x;
    this->y = y;
    this->z = z;
}
Vector3D::~Vector3D()
{
}
double *Vector3D::get_values() const
{
    double *array = new double[3]{this->x, this->y, this->z};
    return array;
}
void Vector3D::set_values(double x_1, double y_1, double z_1)
{
    if (std::isnan(x_1) || std::isnan(y_1) || std::isnan(z_1))
    {
        throw std::invalid_argument("Invalid Argument");
    }
    x = x_1;
    y = y_1;
    z = z_1;
}
double Vector3D::get_magnitude() const
{
    return sqrt(x * x + y * y + this->z * this->z);
}
Vector3D Vector3D::cross_product(Vector3D const &other) const
{
    Vector3D cross(y * other.get_values()[2] - z * other.get_values()[1],
                   z * other.get_values()[0] - x * other.get_values()[2],
                   x * other.get_values()[1] - y * other.get_values()[0]);
    return cross;
}
bool Vector3D::operator<(Vector3D const &other) const
{
    if (this->get_magnitude() < other.get_magnitude())
    {
        return true;
    }
    return false;
}
double Vector3D::operator*(Vector3D const &other) const
{
    return (x * other.get_values()[0] + y * other.get_values()[1] + z * other.get_values()[2]);
}
Vector3D Vector3D::operator+(Vector3D const &other) const
{
    Vector3D add(x + other.get_values()[0], y + other.get_values()[1], z + other.get_values()[2]);
    return add;
}
Vector3D Vector3D::operator-(Vector3D const &other) const
{
    Vector3D minus(x - other.get_values()[0], y - other.get_values()[1], z - other.get_values()[2]);
    return minus;
}

#ifndef MARMOSET_TESTING
int main()
{
    Vector3D vector(5, 2, 5);

    return 0;
}

#endif