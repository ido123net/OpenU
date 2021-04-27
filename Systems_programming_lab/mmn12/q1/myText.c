#include "data.h"

int readText(int type, void *p) /* reading the text and put it in the memory */
{
    int c;
    while ((c = getchar()) != EOF) /* read until EOF */
    {
        if (c == '\n') /* skipping "new line" char */
        {
            continue;
        }
        switch (type)
        {
        case BUFFER:
            if (add_c_buf((Buffer *)p, c) != 0) /* puts char in Buffer memory */
            {
                printf("\nout of memory\n"); /* cant realloc more memory */
                return -1;
            }
            break;

        case LINKEDLIST:
            if (add_c_list((LinkedList *)p, c) != 0) /* puts char in LinkedList memory */
            {
                printf("\nout of memory\n"); /* cant realloc more memory */
                return -1;
            }
            break;

        default:
            break;
        }
    }
    return 0;
}

int printText(int type, void *p) /* printing the text stored in memory */
{
    switch (type)
    {
    case BUFFER:
        print_arr((Buffer *)p);
        break;

    case LINKEDLIST:
        print_list((LinkedList *)p);
        break;

    default:
        break;
    }
    return 0;
}