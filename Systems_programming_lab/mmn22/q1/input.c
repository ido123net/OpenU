#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

extern Set SETA, SETB, SETC, SETD, SETE, SETF;

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
        unsigned short int num = read_num(&token);
        if (num == -1)
        {
            if (strtok(ptr, "\n") != NULL)
            {
                return -1;
            }
            return 0;
        }

        if (num < SET_SIZE && num >= 0)
        {
            add_to_set(set, num);
        }
        else
        {
            return -2;
        }
    }
    return -3;
}

int run_line()
{
    char *ptr = NULL;
    char *token = NULL;
    char *line = NULL;
    size_t len = 0;
    Set setA = NULL;
    Set setB = NULL;
    Set setC = NULL;

    getline(&line, &len, stdin);
    ptr = strdup(line);
    token = strsep(&ptr, " \t\n");

    int func = get_func(token);
    switch (func)
    {
    case READ_SET:
        token = strsep(&ptr, ",");
        remove_spaces(token);
        setA = which_set(token);
        read_set(ptr, &setA);
        break;

    case PRINT_SET:
        token = strsep(&ptr, "\n");
        setA = which_set(token);
        print_set(&setA);
        break;

    case UNION_SET:
    case INTERSECT_SET:
    case SUB_SET:
    case SYMDIFF_SET:
        token = strsep(&ptr, ",");
        remove_spaces(token);
        setA = which_set(token);
        token = strsep(&ptr, ",");
        remove_spaces(token);
        setB = which_set(token);
        token = strsep(&ptr, "\n");
        remove_spaces(token);
        setC = which_set(token);
        apply_set_func(&setA, &setB, &setC, func);
        break;

    case STOP:
        if (strtok(ptr, "\n") != NULL)
        {
            return -1;
        }
        return 0;

    default:
        break;
    }

    free(line);
    return 1;
}
