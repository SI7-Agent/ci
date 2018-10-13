#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/**
 ���������� ������� � ����.
 * @brief record_matr
 * @param name_res
 * @param matr
 * @param rows
 * @param cols
 */

void record_matr(char *name_res[], float **matr, int rows, int cols)
{
    FILE *f_res = fopen(name_res[4], "w");

    fprintf(f_res, "%d ", rows);
    fprintf(f_res, "%d\n", cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            fprintf(f_res, "%8.2f", matr[i][j]);
        fprintf(f_res, "\n");
    }

    fclose(f_res);
}

/**
 ���������� ����� � ����.
 * @brief record_num
 * @param name_res
 * @param num
 */

void record_num(char *name_res[], float num)
{
    FILE *f_res = fopen(name_res[3], "w");

    fprintf(f_res, "%.2f", num);

    fclose(f_res);
}
