#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#include "read_array_test.h"
#include "tick.h"
#include "key.h"
#include "get_size_test.h"
#include "mysort.h"


int main(int argc, char *argv[])
{
    unsigned long long tb, te;
    long pos, pos_end;
    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("I/O error\nFile is not found\n");

        FILE *f_out_error = fopen(argv[2], "w");
        fclose(f_out_error);
        return -1;
    }

    int num;
    int size = 0;

    while(fscanf(f, "%d", &num) == 1)
    {
        pos = ftell(f);
        size++;
    }

    if (size == 0)
    {
        printf("File is empty/contains incorrect data.\n");

        FILE *f_out_error = fopen(argv[2], "w");
        fclose(f_out_error);
        return -1;
    }

    fseek(f, 0, SEEK_END);
    pos_end = ftell(f);

    if (pos != pos_end)
    {
        printf("File contains incorrect data");

        FILE *f_out_error = fopen(argv[2], "w");
        fclose(f_out_error);
        return -1;
    }

    int *array_orig = (int *)malloc(size*sizeof(int));
    int *array_orig_end = array_orig+size;

    int *array_start = array_orig;

    fseek(f, 0, SEEK_SET);

    int *array_for_filter = (int *)malloc(size*sizeof(int));
    int *array_for_filter_end = array_for_filter+size;

    printf("Read array:\n");
    read_array(f, array_orig, array_orig_end);
    output(array_orig, array_orig_end);
    fclose(f);

    int flag = 0;
    int size2;
    if ((argc > 3) && (strcmp(argv[3], "f") == 0))
    {
        flag = 1;
        array_orig = array_start;
        size2 = key(array_orig, array_orig_end, &array_for_filter, &array_for_filter_end);

        if (size2 == -1)
        {
            printf("\nError in filter func");
            return -1;
        }
    }

    if (flag == 1)
    {
        tb = tick();
        mysort(array_for_filter, array_for_filter_end, sizeof(int), comp_int);
        te = tick();

        printf("\nSorted array:\n");
        output(array_for_filter, array_for_filter_end);

        printf("\nSort time: %llu nsec\n", (te - tb) / 2);

        FILE *f_out = fopen(argv[2], "w");
        record(f_out, array_for_filter, array_for_filter_end);
        fclose(f_out);
    }
    else
    {
        array_orig = array_start;
        tb = tick();
        mysort(array_orig, array_orig_end, sizeof(int), comp_int);
        te = tick();

        array_orig = array_start;
        printf("\nSorted array:\n");
        output(array_orig, array_orig_end);

        printf("\nSort time: %llu nsec\n", (te - tb) / 2);

        array_orig = array_start;
        FILE *f_out = fopen(argv[2], "w");
        record(f_out, array_orig, array_orig_end);
        fclose(f_out);
    }

    free(array_for_filter);
    free(array_orig);
}
