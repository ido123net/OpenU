<<<<<<< HEAD
#include "input_handler.h"
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
>>>>>>> mmn22
#include "set.h"

int main()
{
<<<<<<< HEAD
    handle_input();
=======
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
>>>>>>> mmn22
    return 0;
}
