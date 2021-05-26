#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

extern Set SETA, SETB, SETC, SETD, SETE, SETF;

static char *func_names[NUM_FUNC] = {"read_set",
                                     "print_set",
                                     "union_set",
                                     "intersect_set",
                                     "sub_set",
                                     "symdiff_set",
                                     "stop"};

static char *set_names[NUM_SET] = {"SETA",
                                   "SETB",
                                   "SETC",
                                   "SETD",
                                   "SETE",
                                   "SETF"};
Set *which_set(char *set)
{
    /* returning a pointer to the set with the same name NULL if there is no such set */
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

    return NULL;
}

Set *get_set(char **set)
{
    while (isspace(**set))
        (*set)++;
    if (!**set)
    {
        printf("Missing parameter\n");
        return NULL;
    }
    int i;
    for (i = 0; i < NUM_SET; i++)
    {
        if (strncmp(*set, set_names[i], strlen(set_names[i])) == 0)
        {
            *set += strlen(set_names[i]);
            while (isspace(**set))
                (*set)++;
            return which_set(set_names[i]);
        }
    }
    printf("Undefined set name\n");
    return NULL;
}

int get_func(char **token)
{
    int i;
    for (i = 0; i < NUM_FUNC; i++)
    {
        if (strncmp(*token, func_names[i], strlen(func_names[i])) == 0)
        {
            *token += strlen(func_names[i]);
            while (isspace(**token))
                (*token)++;
            if (!**token)
                return i;
            else
                printf("Illegal char - %c after command\n", **token);
            return -1;
        }
    }
    printf("Undefined command name\n");
    return -1;
}

int get_num(char **ptr)
{
    int num = atoi(*ptr);
    while (isspace(**ptr))
        (*ptr)++;
    if (**ptr == '-')
        (*ptr)++;
    while (isdigit(**ptr))
        (*ptr)++;
    while (isspace(**ptr))
        (*ptr)++;
    if (**ptr)
        return -2;
    if (num < -1 || num > 127)
        return -3;
    return num;
}

int read(char **token)
{
    char *set = strsep(token, ",");
    if (!*token)
    {
        printf("Missing comma\n");
        return -1;
    }
    Set *setA = get_set(&set);
    if (!setA)
        return -1;

    Set setB = init_set();
    char *nums = strsep(token, "\0");
    char *snum = strsep(&nums, ",");
    int terminated = 0;
    while (*snum && !terminated)
    {
        int num;
        num = get_num(&snum);

        switch (num)
        {
        case -1:
            terminated = 1;
            break;
        case -2:
            printf("Invalid set member – not an integer\n");
            return -1;

        case -3:
            printf("Invalid set member – value out of range\n");
            return -1;

        default:
            add_to_set(&setB, num);
            snum = strsep(&nums, ",\n");
            break;
        }
    }
    if (!terminated)
    {
        printf("List of set members is not terminated correctly\n");
        return -1;
    }
    while (isspace(*nums))
        nums++;
    if (*nums)
    {
        printf("Extraneous text after end of terminated integer\n");
        return -1;
    }
    read_set(setA, setB);
    return 0;
}

int print(char **token)
{
    char *set = strsep(token, "\n");
    Set *setA = get_set(&set);
    if (!setA)
        return -1;
    while (isspace(*set))
        set++;
    if (*set)
    {
        printf("Extraneous text after end of command\n");
        return -1;
    }
    print_set(setA);
    return 0;
}

int function(char **token, int func)
{
    char *set = strsep(token, ",\n");
    if (!*token)
    {
        printf("Missing comma\n");
        return -1;
    }
    Set *setA = get_set(&set);
    if (!setA)
        return -1;
    set = strsep(token, ",\n");
    if (!*token)
    {
        printf("Missing comma\n");
        return -1;
    }
    Set *setB = get_set(&set);
    if (!setB)
        return -1;
    set = strsep(token, "\n");
    Set *setC = get_set(&set);
    if (!setC)
        return -1;
    while (isspace(*set))
        set++;
    if (*set)
    {
        printf("Extraneous text after end of command\n");
        return -1;
    }
    apply_set_func(setA, setB, setC, func);
    return 0;
}

int run_line()
{
    char *ptr = NULL;
    char *token = NULL;
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    printf("You enter: %s", line);
    ptr = strdup(line);
    while (isspace(*ptr) && *ptr != '\n')
        ptr++;
    /* 
    if (*ptr == EOF)
    {
        printf("\nEOF\n");
        return STOP;
    }
     */
    if (*ptr == '\n')
    {
        printf("blank line\n");
        return -1;
    }
    token = strsep(&ptr, " \t\n\0");
    int func = get_func(&token);
    if (func == -1)
    {
        return -1;
    }
    if (*token)
    {
        printf("Illegal char\n");
        return -1;
    }

    switch (func)
    {
    case READ_SET:
        token = strsep(&ptr, "\0");
        if (!*token)
        {
            printf("Missing parameter\n");
            return -1;
        }
        read(&token);
        break;

    case PRINT_SET:
        token = strsep(&ptr, "\0");
        if (!*token)
        {
            printf("Missing parameter\n");
            return -1;
        }
        print(&token);
        break;

    case UNION_SET:
    case INTERSECT_SET:
    case SUB_SET:
    case SYMDIFF_SET:
        token = strsep(&ptr, "\0");
        if (!*token)
        {
            printf("Missing parameter\n");
            return -1;
        }
        function(&token, func);
        break;

    case STOP:
        if (strtok(ptr, "\n") != NULL)
        {
            return -1;
        }
        return STOP;

    default:
        break;
    }

    free(line);
    return 1;
}
