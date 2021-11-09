#include <iostream>

int main();
void matrix_multiply(double matrixA[], double matrixB[]);

void matrix_multiply(double matrixA[], double matrixB[])
{
    double temp[4]{}; //store matrix A initial vals
    temp[0] = matrixA[0];
    temp[1] = matrixA[1];
    temp[2] = matrixA[2];
    temp[3] = matrixA[3];

    matrixA[0] = (temp[0] * matrixB[0]) + (temp[1] * matrixB[2]);
    matrixA[1] = (temp[0] * matrixB[1]) + (temp[1] * matrixB[3]);

    matrixA[2] = (temp[2] * matrixB[0]) + (temp[3] * matrixB[2]);
    matrixA[3] = (temp[2] * matrixB[1]) + (temp[3] * matrixB[3]);
}

int main()
{
    double matrixA[4]{5, 6, 0, 3};
    double matrixB[4]{9, 3, 7, 0};
    matrix_multiply(matrixA, matrixB);
    return 0;
}