#include <stdlib.h>
#include <stdio.h>

/**
 ���������� ��� ��������.

 * @param i
 * @param j
 * @return ���������� ���� �����, ������� 0, ���� ������� 0, ���� 0.
 */

int comp_int (const void *i, const void *j)
{
    return *(int*)i - *(int*)j;
}
