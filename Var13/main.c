#include "header.h"
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    char* F1 = "F1.txt";
    char* F2 = "F2.txt";
    char* F3 = "F3.txt";
    FILE* file1 = fopen(F1, "w+");
    FILE* file2 = fopen(F2, "w");
    FILE* file3 = fopen(F3, "w");

    if (file1 == NULL || file2 == NULL || file3 == NULL)
        return;
    
    float A, B, C, D, coef[3], x1, x2;
    int N;
    printf("N строк коэффициентов = ");
    scanf_s("%d", &N);

    //Запись коэффициентов в файл F1
    for (int i = 0; i < N; i++)
    {
        A = Random(-5, 5); B = Random(-5, 5); C = Random(-5, 5);
        if (A == 0.0)
        {
            do
            {
                A = Random(-5, 5);
            } while (A == 0.0);
        }
        if (i == N-1)
            fprintf_s(file1, "%f %f %f", A, B, C);
        else
            fprintf_s(file1, "%f %f %f\n", A, B, C);
    }
    rewind(file1);

    //Расчёт дискриминанта и корней. Их запись в файлы F2 и F3
    while (!feof(file1))
    {
        for (int i = 0; i < 3; i++)
            fscanf_s(file1, "%f", &coef[i]);

        D = discriminant(coef[0], coef[1], coef[2]);
        if (D > 0)
        {
            roots(coef[0], coef[1], D, &x1, &x2);
            fprintf(file2, "A = %f, B = %f, C = %f, D = %f, x1 = %f, x2 = %f\n", coef[0], coef[1], coef[2], D, x1, x2);
        }
        else if (D == 0)
        {
            fprintf(file2, "A = %f, B = %f, C = %f, D = %f, x = %f\n", coef[0], coef[1], coef[2], D, root(coef[0], coef[1]));
        }
        else if (D < 0)
        {
            out(file3, coef[0], coef[1], coef[2], D);
        }
        
    }

    fclose(file1); fclose(file2); fclose(file3);
    return 0;
}