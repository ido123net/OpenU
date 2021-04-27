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
        case buffer:
            if (add_c_arr((array *)p, c) != 0)
            {
                printf("\nout of memory\n");
                return -1;
            }
            break;

        case linkedList:
            if (add_c_list((ptr)p, c) != 0)
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
    case buffer:
        print_arr((array *)p);
        break;

    case linkedList:
        print_list((ptr)p);
        break;

    default:
        break;
    }
    return 0;
}