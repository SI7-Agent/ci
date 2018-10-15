float static **p;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#include "get_matrix.h"

/**
 ��������� ������������� ���� ������.

 * @param matr1
 * @param matr2
 * @param rows
 * @param cols
 * @return ���������� ��������� �� �������������� �������.
 */

float **get_sum(float **matr1, float **matr2, int rows, int cols)
{
    float **result = allocate_matrix(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = matr1[i][j] + matr2[i][j];

    return result;
}

/**
 ��������� ��������� ���� ������.

 * @param matr1
 * @param matr2
 * @param rows
 * @param cols
 * @param num1
 * @return ���������� ��������� �� �������������� �������.
 */

float **get_multy(float **matr1, float **matr2, int rows, int cols, int num1)
{
    float **result = allocate_matrix(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            float tmp = 0;
            for (int k = 0; k < num1; k++)
                tmp += matr1[i][k] * matr2[k][j];
            result[i][j] = tmp;
        }

    return result;
}

/**
 ����������� �������� ������� � ������� ��� i-�� ������ � j-��� �������.

 * @param matr
 * @param p
 * @param i
 * @param j
 * @param m
 */

void get_matr(float **matr, float **p, int i, int j, int m)
{
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki< m-1 ; ki++)
    {
        if (ki == i)
            di = 1;
        dj = 0;
        for (kj = 0; kj< m-1; kj++)
        {
            if (kj == j)
                dj = 1;
            p[ki][kj] = matr[ki + di][kj + dj];
        }
    }
}

/**
 ��������� ������������ �������.

 * @param matr
 * @param m
 * @param size
 * @return ���������� �������� �����������.
 */

float determinant(float **matr, int m, int size)
{
    int i, d, k, n;
    if (m == size)
    {
        p = (float**)malloc(m*sizeof(float*));
        for (i = 0; i<m; i++)
            p[i] = (float*)malloc(m*sizeof(float));
    }
    else if (m > 2)
    {
        for (int i = 0; i<m; i++)
            free(p[i]);
        free(p);

        p = (float**)malloc(m*sizeof(float*));
        for (i = 0; i<m; i++)
            p[i] = (float*)malloc(m*sizeof(float));
    }

    d = 0;
    k = 1;
    n = m - 1;
    if (m == 1)
    {
        d = matr[0][0];
        return d;
    }
    if (m == 2)
    {
        d = matr[0][0] * matr[1][1] - (matr[1][0] * matr[0][1]);
        return d;
    }
    if (m>2)
    {
        for (i = 0; i<m; i++)
        {
            get_matr(matr, p, i, 0, m);
            d = d + k * matr[i][0] * determinant(p, n, m);
            k = -k;
        }
    }
    for (int i = 0; i<m; i++)
        free(p[i]);
    free(p);
    return d;
}
