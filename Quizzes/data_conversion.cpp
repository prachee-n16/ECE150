#include <iostream>

int main();

int main()
{
    double KB_to_bits = 3.1;
    KB_to_bits = 3.1 * 1000 * 8;
    std::cout << "3.1 KB is " << KB_to_bits << " bits." << std::endl;

    double CD = ((3.1 * 1000000000) / (1000000)) / 700;
    std::cout << "3.1 GB of data can be stored with " << CD << " CDs." << std::endl;

    double CD_to_audio = (421.2 * 60) / 80;
    std::cout << "421.2 hours of music can be stored with " << CD_to_audio << " CDs." << std::endl;

    double fill_CDs = ((51 * 700) / (75.4 * 1000000 / 8 / 1000000)) / 3600;
    std::cout << "51 CDs will take " << fill_CDs << " hours to fill." << std::endl;
    return 0;
}