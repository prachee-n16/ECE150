#include <iostream>

int main();

int main()
{
    char a = 'Q';
    while (true)
    {
        std::cout << "Enter command: ";
        std::cin >> a;
        if (a == 'Q')
        {
            break;
        }

        int num = 0;
        std::cin >> num;

        char sentence[100]{};
        bool isThis = true;
        for (int i = 0; (isThis); ++i)
        {
            std::cin >> sentence[i];
            if (sentence[i] == '.')
            {
                std::cout << std::endl;
                isThis = false;
            }
            else
            {
                unsigned char k = sentence[i] + num;
                unsigned int l = sentence[i];
                int temp = 0;

                if (k > 90)
                {
                    temp = k - 90;
                    k = 65 + temp;
                }
                std::cout << k;
            }
        }
    }
    return 0;
}