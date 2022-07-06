#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

float Random(int min, int max)
{  
    return (max - min) * ((float)rand() / RAND_MAX) + min;
}

float discriminant(float A, float B, float C)
{
    return B * B - 4 * A * C;
}

float roots(float A, float B, float D, float* x1, float* x2)
{
    *x1 = (-B + sqrt(D)) / (2 * A);
    *x2 = (-B - sqrt(D)) / (2 * A);
}

float root(float A, float B)
{
    float B2 = B, A2 = A;
    return -B2 / 2 * A2;
}

void out(FILE* file3, float A, float B, float C, float D)
{

    fprintf(file3, "A = %f, B = %f, C = %f, D = %f, ", A, B, C, D);
    float first = -B / 2 * A, Square_root = sqrt(abs(D)) / 2 * A, sr = -Square_root;
    if (Square_root < 0)
        fprintf(file3, "x1 = %f - %fi, x2 = %f + %fi\n", first, sr, first, sr);
    else
        fprintf(file3, "x1 = %f + %fi, x2 = %f - %fi\n", first, Square_root, first, Square_root);
}