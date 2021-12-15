// compute the addition of two 32 bit signed integers
// represented as array of boolean values

// HATE THIS QUESTION I GET THE CONCEPT IM LEAVING HERE
#include <iostream>

int main();
void add(bool operand1[32], bool operand2[32]);

void add(bool operand1[32], bool operand2[32])
{
    bool res[32]{};
    int c{};
    for (int i = 0; i < 32; i++)
    {
        if (operand1[i] != 1 && operand2[i] != 1 && c != 1)
        {
            res[i] = operand1[i] + operand2[i] + c;
        }
        else if (c == 1)
        {
            if (operand1 == 0 || operand2 == 0)
            {
                res[i] = 0;
                c = 1;
            }
            else if (operand1 == 1 && operand2 == 1)
            {
                res[i] = 0;
                c = 1;
            }
        }
    }
}

int main()
{
}