#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "set.h"
#include "input.h"

Set SETA, SETB, SETC, SETD, SETE, SETF;

Set *which_set(char *set)
{
    /* returning a pointer to the complex number with the same name as the char */
    if (!strcmp(set, "SETA"))
        return &SETA;
    if (!strcmp(set, "SETB"))
        return &SETB;
    if (!strcmp(set, "SETC"))
        return &SETC;
    if (!strcmp(set, "SETD"))
        return &SETD;
    if (!strcmp(set, "SETE"))
        return &SETE;
    if (!strcmp(set, "SETF"))
        return &SETF;

    return NULL; /* never reaches hear */
}

void remove_spaces(char *s)
{
    const char *d = s;
    do
    {
        while (isspace(*d))
        {
            ++d;
        }
    } while ((*s++ = *d++));
}

int get_func(const char *delims)
{
    while (isspace(ptr[0]))
        ptr++;

    char *token;
    if ((token = strsep(&ptr, delims)) == NULL)
    {
        // TODO get new line
        return -1;
    }

    int i;
    for (i = 0; i < NUM_FUNC; i++)
    {
        char *f = func_names[i];
        if (!strcmp(token, f))
            return i;
    }
    return -1;
}

Set *get_set(const char *delims)
{
    char *token = strsep(&ptr, delims);
    remove_spaces(token);
    if ((token == NULL))
    {
        // TODO get new line
        return NULL;
    }
    return which_set(token);
}

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, stdin)) != -1)
    {
        ptr = strdup(line);
        char *ptr;

        if (ptr == NULL)
        {
            fprintf(stderr, "strdup failed");
            exit(EXIT_FAILURE);
        }
        int func;
        if ((func = get_func(" \t")) >= 0)
        {
            printf("%s\n", func_names[func]);
        }
        Set *tmp;
        if ((tmp = get_set("\n")))
        {

        }

    }
    free(ptr);
    free(line);
    exit(EXIT_SUCCESS);
}
