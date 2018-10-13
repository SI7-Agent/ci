#include <stdlib.h>
#include <stdio.h>

/**
 Фильтрует указанным способом массив array_start,
 под полученное число элементов создаетс¤ массив array2_start,
 в который копируютс¤ элементы, удовлетвор¤ющие фильтру.

 * @param array_start
 * @param array_end
 * @param array2_start
 * @param array2_end

 * @return возвращает размер отфильтрованного массива
 * или код ошибки в случае некорректных данных
 */

int key(int *array_start, int *array_end, int **array2_start, int **array2_end)
{
    int *start_orig = array_start;
    int size = array_end - array_start;

    int average = 0;
    int ready_to_filter = 0;

    if (size == 0)
    {
        printf ("Incorrect Data");
        return -1;
    }

    array_start = start_orig;
    for (int i = 0; i < size; i++)
    {
        average = average + *array_start;
        if (array_start != array_end)
            array_start++;
    }

    average = average/size;

    array_start = start_orig;
    for (int i = 0; i < size; i++)
    {
        if (*array_start > average)
            ready_to_filter++;

        if (array_start != array_end)
            array_start++;
    }

    if (ready_to_filter == 0)
        return -2;

    *array2_start = (int *)realloc(*array2_start, ready_to_filter*sizeof(int));
    *array2_end = *array2_start+ready_to_filter;

    int *start_orig2 = *array2_start;

    array_start = start_orig;
    int size2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (*array_start > average)
        {
            int temp = *array_start;
            *(start_orig2) = temp;
            size2++;

            if (start_orig2 != *array2_end)
                start_orig2++;
        }

        if (array_start != array_end)
            array_start++;
    }

    return ready_to_filter;
}
