#include "data.h"

int readText(int type, void *p)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            continue;
        }
        switch (type)
        {
        case BUFFER:
            if (add_c_buf((Buffer *)p, c) != 0)
            {
                printf("\nout of memory\n");
                return -1;
            }
            break;

        case LINKEDLIST:
            if (add_c_list((LinkedList *)p, c) != 0)
            {
                printf("\nout of memory\n");
                return -1;
            }
            break;

        default:
            break;
        }
    }
    return 0;
}

int printText(int type, void *p)
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