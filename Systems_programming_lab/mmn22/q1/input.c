#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "set.h"
#include "input.h"

Set SETA, SETB, SETC, SETD, SETE, SETF;

Set which_set(char *set)
{
    /* returning a pointer to the complex number with the same name as the char */
    if (!strcmp(set, "SETA"))
        return SETA;
    if (!strcmp(set, "SETB"))
        return SETB;
    if (!strcmp(set, "SETC"))
        return SETC;
    if (!strcmp(set, "SETD"))
        return SETD;
    if (!strcmp(set, "SETE"))
        return SETE;
    if (!strcmp(set, "SETF"))
        return SETF;

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

int get_func(char *token)
{
    int i;
    for (i = 0; i < NUM_FUNC; i++)
    {
        char *f = func_names[i];
        if (!strcmp(token, f))
            return i;
    }
    return -1;
}

int read_num(char **token)
{
    int i;
    int sign = 1;
    int size = 3;
    char num[size];
    while (isspace(**token))
        (*token)++;
    if (**token == '-')
    {
        sign = -1;
        (*token)++;
    }
    for (i = 0; isdigit(**token) && i < size; (*token)++)
    {
        num[i++] = **token;
    }
    while (**token != ',')
    {
        if (!isspace(**token))
            return -1;
        (*token)++;
    }
    (*token)++;
    return sign * atoi(num);
}

int read_set(char *ptr, Set *set)
{
    char *token = strsep(&ptr, "\n");
    while (isspace(*token))
        token++;
    while (*token)
    {
        int num = read_num(&token);
        if (num < SET_SIZE && num >=0)
        {
            add_to_set(set, num);
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    SETA = init_set();
    /* add_to_set(SETA, 0);
    add_to_set(SETA, 4);
    add_to_set(SETA, 32);
    add_to_set(SETA, 56); */
    char *line = NULL;
    char *ptr = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token;
    Set tmp;

    nread = getline(&line, &len, stdin);
    ptr = strdup(line);
    token = strsep(&ptr, " \t\n");

    int func = get_func(token);
    switch (func)
    {
    case READ_SET:
        token = strsep(&ptr, ",");
        remove_spaces(token);
        tmp = which_set(token);
        read_set(ptr, &tmp);
        break;

    case PRINT_SET:
        token = strsep(&ptr, "\n");
        tmp = which_set(token);
        print_set(tmp);
        break;

    case UNION_SET:
        break;

    case INTERSECT_SET:
        break;

    case SUB_SET:
        break;

    case SYMDIFF_SET:
        break;

    case STOP:
        break;

    default:
        break;
    }

    free(line);
    exit(EXIT_SUCCESS);
}
