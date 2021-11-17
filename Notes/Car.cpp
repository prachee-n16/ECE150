#include <iostream>

class Car
{
public:
    Car(int year, std::string manufacturer, std::string color);
    ~Car();
    // Overloaded operator
    bool operator<(Car const &other);
    // getters and setters
    void drive();
    void brake();
    int get_year() const;
    void set_year(int year);
    std::string get_manufacturer() const;
    void set_manufacturer(std::string manufacturer);
    std::string get_color() const;
    void set_color(std::string color);

private:
    int year;
    std::string manufacturer;
    std::string color;
};

Car::Car(int year, std::string manufacturer, std::string color)
{
    this->year = year;
    this->manufacturer = manufacturer;
    this->color = color;
}
Car::~Car()
{
}

bool Car::operator<(Car const &other)
{
    if (this->year < other.get_year())
    {
        return true;
    }
    return false;
}

int Car::get_year() const { return this->year; }
void Car::set_year(int year) { this->year = year; }

std::string Car::get_manufacturer() const { return this->manufacturer; }
void Car::set_manufacturer(std::string manufacturer) { this->manufacturer = manufacturer; }

std::string Car::get_color() const { return this->color; }
void Car::set_color(std::string color) { this->color = color; }

void Car::drive() { std::cout << "Vroom" << std::endl; }
void Car::brake() { std::cout << "Skieet" << std::endl; }