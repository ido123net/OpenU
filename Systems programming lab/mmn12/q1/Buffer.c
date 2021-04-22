#include <stdlib.h>
#include <stdio.h>
#include "myText.h"

static int arr_size = size;

array *initArray()
{
    array *arr = (array *)malloc(sizeof(array));
    arr->text = malloc(size);
    arr->len = 0;
    return arr;
}

int add_c_arr(array *arr, char c)
{
    if (arr->len >= arr_size)
    {
        arr_size = arr_size + size;
        char *new_text = realloc(arr->text, arr_size);
        if (!new_text)
        {
            return -1;
        }
        arr->text = new_text;
    }
    arr->text[(arr->len)++] = c;
}

int print_arr(array *arr)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (i % size == 0 && i != 0)
        {
            putchar('\n');
        }
        putchar(arr->text[i]);
    }
    return 0;
}

int free_arr(array *arr)
{
    free(arr->text);
    free(arr);
    return 0;
}