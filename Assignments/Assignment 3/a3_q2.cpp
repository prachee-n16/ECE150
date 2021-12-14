#include <iostream>

// Function declarations
int main();
int get_assignment_number();
int get_course_number();

// Function definitions
int main()
{
    std::cout << "ECE" << get_course_number()
              << ": Assignment " << get_assignment_number()
              << std::endl;
    return 0;
}

// Function definitions
// int get_assignment_number()
int get_assignment_number()
{
    return 3;
}

// int get_course_number()
//--> incorrect because it is called above in main
//--> compiler isn't sure what function you are referring to
// Minimum change would involve moving these function definition and declaration above where its first called
int get_course_number()
{
    return 150;
}

// Define function first to inform compiler of its existence