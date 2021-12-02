#include <iostream>
#include <cmath>

class Complex
{
public:
    Complex();
    Complex(double x, double y);
    ~Complex();
    void add_value(double add_real, double add_imag);
    void add_value(Complex add_complex);
    void get_value(double &real_val, double &imag_val);

private:
    double real;
    double imaginary;
};

Complex::Complex()
{
    this->real = 0;
    this->imaginary = 0;
}
Complex::Complex(double x, double y)
{
    this->real = x;
    this->imaginary = y;
}
Complex::~Complex()
{
}
void Complex::add_value(double add_real, double add_imag)
{
    this->real = this->real + add_real;
    this->imaginary = this->imaginary + add_imag;
}
void Complex::add_value(Complex add_complex)
{
    this->imaginary = this->imaginary + add_complex.imaginary;
    this->real = this->real + add_complex.real;
}
void Complex::get_value(double &real_val, double &imag_val)
{
    real_val = this->real;
    imag_val = this->imaginary;
}

#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main()
{
    Complex object(2, 3);
    double x = 3.0;
    double y = 4.0;

    //test failed is get value
    //test add value
    //add_value
    return 0;
}
#endif