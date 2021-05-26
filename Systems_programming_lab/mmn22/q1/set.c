#include <stdio.h>
#include <stdlib.h>
#include "set.h"

void add_to_set(Set *set, unsigned short int num)
{
    int group = num / SIZE;     /* the group of the num */
    int bit_index = num % SIZE; /* bit to change to one */
    (*set)->arr[group] |= (1 << bit_index);
}

void read_set(Set *setA, Set setB)
{
    int i;
    for (i = 0; i < SET_SIZE / SIZE; i++)
        (*setA)->arr[i] = setB->arr[i];
}

void apply_set_func(Set *setA, Set *setB, Set *setC, int type)
{
    int i;
    for (i = 0; i < SET_SIZE / SIZE; i++)
    {
        int group;
        for (group = 0; group < SET_SIZE / SIZE; group++)
        {
            switch (type)
            {
            case UNION_SET:
                (*setC)->arr[i] = (*setA)->arr[i] | (*setB)->arr[i];
                break;

            case INTERSECT_SET:
                (*setC)->arr[i] = (*setA)->arr[i] & (*setB)->arr[i];
                break;

            case SUB_SET:
                (*setC)->arr[i] = (*setA)->arr[i] & ~((*setB)->arr[i]);
                break;

            case SYMDIFF_SET:
                (*setC)->arr[i] = (*setA)->arr[i] ^ (*setB)->arr[i];
                break;

            default:
                break;
            }
        }
    }
}

int print_group(int group, unsigned short int content)
{
    int bits_on = 0;
    int j;
    for (j = 0; j < SIZE; j++)
    {
        unsigned short int k = (1 << j);
        if (content & k)
        {
            bits_on++;
            printf("%ld\t", (group * SIZE) + j);
        }
    }
    if (content)
    {
        putchar('\n');
    }
    return bits_on;
}

int print_set(Set *set)
{
    int bits_on = 0;
    int group;
    for (group = 0; group < SET_SIZE / SIZE; group++)
    {
        bits_on += print_group(group, (*set)->arr[group]);
    }
    if (!bits_on)
        printf("The set is empty\n");
    return bits_on;
}

Set init_set()
{
    Set set = malloc(sizeof(arr));
    return set;
}