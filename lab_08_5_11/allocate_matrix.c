#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/**
 �������� ������ ��� ������������ �������.
 * @brief allocate_matrix
 * @param rows
 * @param cols
 * @return ���������� ��������� �� ������ ������� ����������.
 */

float **allocate_matrix(int rows, int cols)
{
    float **ptrs, *data;

    ptrs = malloc(rows * sizeof(float*));
    data = malloc(rows * cols * sizeof(float));

    for (int i = 0; i < rows; i++)
        ptrs[i] = data + i * cols;

    return ptrs;
}
