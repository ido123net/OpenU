#include "data.h"

static int arr_size = size;

Buffer *initBuffer()
{
    Buffer *arr = (Buffer *)malloc(sizeof(Buffer));
    arr->text = calloc(size, sizeof(char));
    arr->len = 0;
    return arr;
}

int add_c_buf(Buffer *arr, char c)
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
    return 0;
}

int print_arr(Buffer *arr)
{
    int i = 0;
    while (i < arr->len)
    {
        if (i % size == 0 && i != 0)
        {
            putchar('\n');
        }
        putchar((arr->text)[i]);
        i++;
    }
    putchar('\n');
    return 0;
}

int free_arr(Buffer *arr)
{
    free(arr->text);
    free(arr);
    return 0;
}