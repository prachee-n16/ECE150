#include <iostream>
class Vehicle
{
public:
    Vehicle(); // default constructor
    // Vehicle(std::string color, int num_seats, std::string *passenger_names, std::size_t num_passengers); // data constructor
    ~Vehicle();
    virtual void drive() = 0;
    void stop();
    virtual void add_passenger(std::string name) = 0;

protected: // Protected is another identifier like public and private
    std::string color;
    int num_seats;
    std::string *passenger_names;
    std::size_t num_passengers;
};

Vehicle::Vehicle()
{
    this->color = "";
    this->num_seats = 0;
    this->passenger_names = nullptr;
    this->num_passengers = 0;
}
Vehicle::~Vehicle()
{
    delete[] passenger_names;
    passenger_names = nullptr;
}
void Vehicle::stop()
{
    std::cout << "Burr" << std::endl;
}

class Car : public Vehicle
{
public:
    Car();
    void drive();
    void add_passenger(std::string name);
};
Car::Car()
{
    this->color = "";
    this->num_seats = 5;
    this->passenger_names = nullptr;
    this->num_passengers = 0;
}
void Car::drive()
{
    std::cout << "Vroom" << std::endl;
}
void Car::add_passenger(std::string name)
{
    if (num_passengers >= 5)
    {
        return;
    }
    std::string *new_passengers = new std::string[num_passengers + 1];
    for (int i{}; i < num_passengers; i++)
    {
        new_passengers[i] = passenger_names[i];
    }
    new_passengers[num_passengers + 1] = name;
    this->num_passengers++;
    delete[] passenger_names;
    passenger_names = new_passengers;
}

class Motorcycle : public Vehicle
{
public:
    Motorcycle();
    void drive();
    void add_passenger(std::string name);
};
Motorcycle::Motorcycle()
{
    this->color = "";
    this->num_seats = 2;
    this->passenger_names = nullptr;
    this->num_passengers = 0;
}
void Motorcycle::drive()
{
    std::cout << "Vroom Vroom" << std::endl;
}
void Motorcycle::add_passenger(std::string name)
{
    if (num_passengers >= 2)
    {
        return;
    }
    std::string *new_passengers = new std::string[num_passengers + 1];
    for (int i{}; i < num_passengers; i++)
    {
        new_passengers[i] = passenger_names[i];
    }
    new_passengers[num_passengers + 1] = name;
    this->num_passengers++;
    delete[] passenger_names;
    passenger_names = new_passengers;
}
int main()
{
    Car car{};
    car.drive();
    car.stop();
    return 0;
}