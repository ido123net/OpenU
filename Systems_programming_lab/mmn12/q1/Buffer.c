#include "data.h"

static int arr_size = size; /* total size saved in memory for the Buffer */

Buffer *initBuffer() /* initialize Buffer */
{
    Buffer *buf = (Buffer *)malloc(sizeof(Buffer)); /* pointer to memory for the Buffer */
    buf->text = calloc(size, sizeof(char));         /* pointer to memory for the text */
    buf->len = 0;                                   /* length of text start at 0 */
    return buf;                                     /* the pointer for the Buffer */
}

int add_c_buf(Buffer *buf, char c) /* adds char to buffer */
{
    if (buf->len >= arr_size) /* if there is no place for more characters */
    {
        arr_size = arr_size + size;                    /* increase Buffer size */
        char *new_text = realloc(buf->text, arr_size); /* tries to realloc more memory */
        if (!new_text)                                 /* fails to realloc more memory */
        {
            return -1;
        }
        buf->text = new_text; /* update pointer of text in Buffer */
    }
    buf->text[(buf->len)++] = c; /* adds the new char */
    return 0;
}

int print_arr(Buffer *buf) /* print the text in specific size per line */
{
    int i = 0;
    while (i < buf->len)
    {
        if (i % size == 0 && i != 0) /* new line every {size} characters */
        {
            putchar('\n');
        }
        putchar((buf->text)[i]); /* print the char */
        i++;
    }
    putchar('\n'); /* add new line at the end of the printed text */
    return 0;
}

int free_arr(Buffer *buf) /* free the memory */
{
    free(buf->text); /* free the memory saved for text */
    free(buf);       /* free the memory saved for data structure */
    return 0;
}