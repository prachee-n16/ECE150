#include <iostream>

//4.01 Class Data Structures
//Simulate three-body problem for stars
//Each star has a position x, y, and z, velocity v_x, v_y, v_z and a mass m
//Store information in a class instead of just having multiple arrays

class Body(const &a, const &b);
int main();
//refer to a and b and not some copy of it
class Body(const &a, const &b)
{ //Class names are capitalized
public:
    double position_[3]; //km
    double velocity_[3]; //km/h
    double mass_;        //kg

    //some for loop
    //has all of the informatio needed to describe star

    return position_;
};

int main()
{
    //create an instance for this class
    Body earth{{150, 0.0, 0.0}, {0.0, 100, 0.0}, 5};
    Body tmp{earth}; //stores earths values
    tmp.mass_ = 0.4;
    //objects can be passed as arguments

    //access mass
    //std::cout << earth.position_[0] << std::endl;
    return 0;
};