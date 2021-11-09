#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif

void matrix_multiply(double matrixA[], double matrixB[]);

void matrix_multiply(double matrixA[], double matrixB[])
{

    double matrix_result[4]{};

    matrix_result[0] = ((matrixA[0] * matrixB[0]) + (matrixA[1] * matrixB[2]));
    matrix_result[1] = ((matrixA[0] * matrixB[1]) + (matrixA[1] * matrixB[3]));
    matrix_result[2] = ((matrixA[2] * matrixB[0]) + (matrixA[3] * matrixB[2]));
    matrix_result[3] = ((matrixA[2] * matrixB[1]) + (matrixA[3] * matrixB[3]));

    for (int i = 0; i < 4; i++)
    {
        matrixA[i] = matrix_result[i];
    }
    std::cout << matrixA[0] << std::endl;
    std::cout << matrixA[1] << std::endl;

    std::cout << matrixA[2] << std::endl;
    std::cout << matrixA[3] << std::endl;
}

#ifndef MARMOSET_TESTING
int main()
{
    double matrixA[4]{5, 6, 0, 3};
    double matrixB[4]{9, 3, 7, 0};
    matrix_multiply(matrixA, matrixB);
}
#endif
