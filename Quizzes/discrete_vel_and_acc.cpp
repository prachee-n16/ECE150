#include <iostream>

#ifndef MARMOSET_TESTING
int main();
void output_velocity_and_acceleration(double position_measurements[], std::size_t qty_measurements);
#endif

#ifndef MARMOSET_TESTING
int main()
{
    const std::size_t qty_measurements{1};
    double position_measurements[qty_measurements]{1.3};
    output_velocity_and_acceleration(position_measurements, qty_measurements);
    return 0;
}
#endif

void output_velocity_and_acceleration(double position_measurements[], std::size_t qty_measurements)
{
    if (qty_measurements < 2)
    {
        std::cout << "Insufficient measurements for velocity calculation." << std::endl;
    }
    else
    {
        std::cout << "Velocity calculations [m/s]:" << std::endl;

        for (int i = 0; i < qty_measurements - 1; i++)
        {
            double velocity = (position_measurements[i + 1] - position_measurements[i]);
            std::cout << velocity << " ";
        }
    }

    if (qty_measurements < 3)
    {
        std::cout << "Insufficient measurements for acceleration calculation." << std::endl;
    }
    else
    {
        std::cout << "Acceleration calculations [m/s]:" << std::endl;
        for (int i = 0; i < qty_measurements - 2; i++)
        {
            double velocity1 = (position_measurements[i + 1] - position_measurements[i]);
            double velocity2 = (position_measurements[i + 2] - position_measurements[i + 1]);
            double acceleration = velocity2 - velocity1;

            std::cout << acceleration << " ";
        }
    }
}