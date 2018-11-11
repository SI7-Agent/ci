/**
 ��������� ������� �������� ��������� ������� �������.

 * @param array_start
 * @param array_end
 * @param start_orig
 * @param size
 * @return ���������� ������� �������� ��������� ������� �������.
 */

int get_average(int *array_start, int *array_end, int *start_orig, int size)
{
    int average = 0;
    array_start = start_orig;
    for (int i = 0; i < size; i++)
    {
        average = average + *array_start;
        if (array_start != array_end)
            array_start++;
    }

    average = average/size;
    return average;
}

/**
 ��������� ����� ���������, ��������� ��� ����������.

 * @param array_start
 * @param array_end
 * @param start_orig
 * @param size
 * @param average
 * @return ���������� ����� ���������, ��������� ��� ����������.
 */

int get_filt_elems(int *array_start, int *array_end, int *start_orig, int size, int average)
{
    int ready_to_filter = 0;
    array_start = start_orig;
    for (int i = 0; i < size; i++)
    {
        if (*array_start > average)
            ready_to_filter++;

        if (array_start != array_end)
            array_start++;
    }
    return ready_to_filter;
}

/**
 �������� ��������, ��������� ��� ����������, � ��������� ������.

 * @param array_start
 * @param array_end
 * @param start_orig
 * @param size
 * @param average
 * @param start_orig2
 * @param array2_end
 */

void get_array_for_filter(int *array_start, int *array_end, int *start_orig, int size, int average, int *start_orig2, int *array2_end)
{
    array_start = start_orig;
    int size2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (*array_start > average)
        {
            int temp = *array_start;
            *(start_orig2) = temp;
            size2++;

            if (start_orig2 != array2_end)
                start_orig2++;
        }

        if (array_start != array_end)
            array_start++;
    }
}
