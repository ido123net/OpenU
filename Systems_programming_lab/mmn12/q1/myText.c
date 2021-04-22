#include "myText.h"

int readText(data_struct type, void *p)
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
            add_c_arr((array *)p, c);
            break;

        case linkedList:
            add_c_list((ptr)p, c);
            break;

        default:
            break;
        }
    }
    return 0;
}

int printText(data_struct type, void *p)
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
    printf("\n");
    return 0;
}