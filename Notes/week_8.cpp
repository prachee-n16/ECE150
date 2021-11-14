//Introduction to Classes
//Basic definition: Classes aggregate (combine elements) and protect data

//4.1 The class data structure
//Consider three-body problem: Determine motion of three celestial bodies
//moving under no influence other mutual gravity

//Class can contain all information to describe one star
//Class names are capitalized; Member variable ends with underscore

//Declaring a class:
class Body;
//Declaring a function that returns a body
//Issue: everytime object is passed as argument, you have significant amount of copying
Body center_of_mass(Body a, Body b);
//So, use pass by constant reference
Body center_of_mass(Body const &a, Body const &b);
//Defining a class:
class Body
{
public:
    //Member variables
    double position_[3]; //km
    double velocity_[3]; //km/h
    double mass_;        //kg
};

//4.02 Namespaces, std::cout and std::ostream

int main();
int main()
{
    //Instance of class
    Body earth{{149.6e6, 0, 0}, {0, 107e3, 0}, 5.972e24}
        //Access member variables using .
        std::cout
        << earth.mass_ << std::endl;
    std::cout << earth.position_[1] << std::endl;
    //Possible to mess around with them
    for (std::size_t k{0}; k < 3; ++k)
    {
        earth.position_[k] += 0.1 * earth.velocity_[k];
    }

    //Copy over earth entries to mars
    Body mars{earth};
    //Objects can be passed as arguments
    //e.g. double speed (Body a); --> a = tmp, Earth

    return 0;
    //Memory for double is deallocated with return
}