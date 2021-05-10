#include "input_handler.h"

int handle_input()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    if ((nread = getline(&line, &len, stdin)) == -1)
    {
        char delims[] = " ";

        char *p = strtok_single(line, delims);

        while (p)
        {
            printf("%s\n", *p ? p : "<empty>");

            p = strtok_single(NULL, delims);
        }
    }
    return 0;
}

char *strtok_single(char *str, char const *delims)
{
    static char *src = NULL;
    char *p, *ret = 0;

    if (str != NULL)
        src = str;

    if (src == NULL)
        return NULL;

    if ((p = strpbrk(src, delims)) != NULL)
    {
        *p = 0;
        ret = src;
        src = ++p;
    }
    else if (*src)
    {
        ret = src;
        src = NULL;
    }

    return ret;
}