#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

int main()
{
    char *line;
    size_t len;
    char *pch;
    getline(&line, &len, stdin);
    pch = strtok(line, " \t");
    while (pch != NULL)
    {
        printf("s=%s\n", pch);
        pch = strtok(NULL, " \t");
    }
    free(line);
    return 0;
}
