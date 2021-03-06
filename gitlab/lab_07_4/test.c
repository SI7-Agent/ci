#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "read_array_test.h"
#include "tick.h"
#include "key.h"
#include "get_size_test.h"
#include "mysort.h"
#include "do_filter.h"

int main()
{
    printf("Reading normal file\n");
    FILE *f1 = fopen("in_1.txt", "r");

    int size = get_size(f1);

    int *array_orig1 = read_array(f1, size);
    int *array_orig_end1 = array_orig1 + size;

    int *array_for_filter1 = NULL;
    int *array_for_filter_end1 = NULL;

    int key_item = key(array_orig1, array_orig_end1, &array_for_filter1, &array_for_filter_end1);

    if ((key_item != -1) && (key_item != -2))
        printf("Test passed\n\n");
    else
        printf("\nTest failed\n\n");

    free(array_orig1);
    free(array_for_filter1);
    fclose(f1);

    //-----------------------------

    printf("Reading empty file\n");
    FILE *f2 = fopen("in_2.txt", "r");

    size = get_size(f2);

    if (size == 0)
        printf("Test passed\n\n");
    else
        printf("\nTest failed\n\n");
    fclose(f2);

    //-----------------------------

    printf("Filtered array is empty\n");
    FILE *f3 = fopen("in_3.txt", "r");

    size = get_size(f3);

    int *array_orig2 = read_array(f3, size); 
    int *array_orig_end2 = array_orig2 + size;

    int *array_for_filter2 = NULL;
    int *array_for_filter_end2 = NULL;

    key_item = key(array_orig2, array_orig_end2, &array_for_filter2, &array_for_filter_end2);

    if (key_item <= 0)
        printf("Test passed\n\n");
    else
        printf("Test failed\n\n");

    free(array_orig2);
    free(array_for_filter2);
    fclose(f3);

    //-----------------------------

    printf("Reading file with incorrect data \n");
    FILE *f4 = fopen("in_4.txt", "r");

    int pos = 0;
    pos = get_pos(f4);
    fseek(f4, 0, SEEK_END);
    int pos_end = 0;
    pos_end = ftell(f4);

    if (pos != pos_end)
        printf("Test passed\n\n");
    else
        printf("\nTest failed\n\n");
    fclose(f4);
	
	//-----------------------------
	
    printf("Testing sort time \n");
    FILE *f5 = fopen("in_1.txt", "r");
    int *array_orig5 = read_array(f5, size);;
    int *array_orig_end5 = array_orig_end1;
	
    unsigned long long tb, te;
    tb = tick();
    mysort(array_orig5, array_orig_end5 - array_orig5, sizeof(int), comp_int);
    te = tick();
    printf("Mysort time is: %d\n", (te - tb));
	
    unsigned int middle_t = 0;

    for(int i = 0; i < 10; i++)
    {
        tb = tick();
        qsort(array_orig5, array_orig_end5 - array_orig5, sizeof(int), comp_int);
        te = tick();
        middle_t += te - tb;
    }
    middle_t /= 10;
	
    printf("Qsort average time is: %d nsec\n", middle_t);
    fclose(f5);
    printf("Test passed\n\n");
	
    //-----------------------------
	
    printf("Testing key func \n");
    FILE *f6 = fopen("in_5.txt", "r");
    int size6 = get_size(f6);
    int *array_orig6 = read_array(f6, size6);
    int *array_orig_end6 = array_orig6 + size6;

    int *array_for_filter6 = NULL;
    int *array_for_filter_end6 = NULL;

    key(array_orig6, array_orig_end6, &array_for_filter6, &array_for_filter_end6);
    FILE *f6o = fopen("out_5.txt", "r");
    int flag = 1;
    int var_fr_file;
    for (; (array_for_filter6 != array_for_filter_end6) && (flag); array_for_filter6++)
    {
        fscanf(f6o, "%d", &var_fr_file);
        if (*array_for_filter6 != var_fr_file)
            flag = 0;
    }
    if (flag)
        printf("Test passed\n\n");
    else
    {
        printf("Test failed\n\n");
    }
	
    free(array_orig6);
    free(array_for_filter6);
    fclose(f6);
    fclose(f6o);
	
    //------------------------------
	
    printf("Testing mysort func \n");
    FILE *f7 = fopen("in_6.txt", "r");
    int size7 = get_size(f7);
    int *array_orig7 = read_array(f7, size7);
    int *array_orig_end7 = array_orig7 + size7;

    mysort(array_orig7, size7, sizeof(int), comp_int);
    FILE *f7o = fopen("out_6.txt", "r");
    flag = 1;
    for (; (array_orig7 != array_orig_end7) && (flag); array_orig7++)
    {
        fscanf(f7o, "%d", &var_fr_file);
        if (*array_orig7 != var_fr_file)
            flag = 0;
    }
    if (flag)
        printf("Test passed\n\n");
    else
        printf("Test failed\n\n");
	
    free(array_orig7);
    fclose(f7);
    fclose(f7o);
	
    return 0;
}
