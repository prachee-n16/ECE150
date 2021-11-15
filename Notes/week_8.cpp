#include <iostream>
#include <cmath>
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
//Everything in standard library is in the std namespace
//std::sin etc. and few seldom exceptions assert() and M_PI

//Create a namespace
namespace ca_uwaterloo_p4nanda
{
    //some function in here
}

//4.03
//Consider this vector 3D class
//Let's try 2-norm
//Sum of two vectors + scalar multiplication
//Cross product and projection
class Vector_3d;
class Vector_3d
{
public:
    double x_;
    double y_;
    double z_;
};

double norm(Vector_3d const &u);
double inner_product(Vector_3d const &u, Vector_3d const &v);

double inner_product(Vector_3d const &u, Vector_3d const &v)
{
    return u.x_ * v.x_ + u.y_ * v.y_ + u.z_ * v.z_;
}
double norm(Vector_3d const &u)
{
    return std::sqrt(inner_product(u, u));
}

//Array class
//You can not create one because C++ needs to know the size at compile time
//Classes can be dynamically allocated arrays

//Pair class
//When a function acts on a object, it is passed by reference
//If we wanted more info returned, additional arguments need to be passed
//Instead consider this
class Pair;
//function that returns a pair object
//Pair maxmin(Array const &array);
//returns first and second value (RETURN TWO VALUES)
class Pair
{
public:
    std::size_t first_;
    std::size_t second_;
};
//declare function here

//4.4 Operator overloading
//Let's say you have a class Rational
//When you add p+q where p and q are objects of class
//you have to say add(p+q) and then convert that to a string
//what if you could easily say p+q
class Rational
{
public:
    int numer_;
    int denom_;
};
//Operator overloading
Rational operator+(Rational const &p, Rational const &q);
Rational operator+(Rational const &p, Rational const &q)
{
    //return p+q being added together
    return p;
}
//Now when you add two objects, you can define it for them
//Can overload anything but :: or .

//Can be done for all previous functions but remember
//It does not know anything about commutavity or symmetry
//Dont have double meaning for an operator and make sure it makes sense

//4.5 Issues with member variables
//Issue with a rational class is you can't have x/0
//Could ensure by using assert
//assert ( (p.denom_ !=0.0) && (q.denom_ != 0.0))
//expensive for checks.
//Create a normal form then
//Doesnt work though

//SOLUTION: Deal with the lifetime of an object
//Constructors deal with object initialization
//Member functions access and manipulate
//Destructors will deal with clean up of the objects

//Known as encapsulation: protects information from the user

//4.6 Using member functions
//users should only be able to call functions associated with
//the class
//like member variables you have member functions
//std::cout.precision(16)
//classname.function()
//We didn’t have to deal with the constructors or the destructors
///because the compiler deal with these:
//– The constructor was called when the local variable was declared
//– The destructor was called when the local variable went out of scope

//4.7 Throw and catch exceptions
//throw std::some_error {
//code
//} else {}

//need to catch them so program continues executing
//try {}
//catch (...)
//multiple catches (cascading catch blocks)
//exceptions are expensive

//4.08 Classes, encapsulation and constructors
//you can have private variables
//private:
//int something?
//at the same time keep public variables

int main();
int main()
{
    //4.01
    //Instance of class
    Body earth{{149.6e6, 0, 0}, {0, 107e3, 0}, 5.972e24};
    //Access member variables using .
    std::cout << earth.mass_ << std::endl;
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

    //4.02
    std::clog << "This can be redirected to a log file" << std::endl;
    //same as cout?
    std::endl(std::cout << "TEST!"); //--> blows my mind
    return 0;
    //Memory for double is deallocated with return
}