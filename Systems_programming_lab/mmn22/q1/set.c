#include <stdio.h>
#include <stdlib.h>
#include "set.h"

void add_to_set(Set set, unsigned short int num)
{
    int group = num / SIZE;     /* the group of the num */
    int bit_index = num % SIZE; /* bit to change to one */
    set->arr[group] |= (1 << bit_index);
}

Set apply_set_func(Set setA, Set setB, int type)
{
    Set new_set = init_set();
    int i;
    for (i = 0; i < SET_SIZE / SIZE; i++)
    {
        int group;
        for (group = 0; group < SET_SIZE / SIZE; group++)
        {
            switch (type)
            {
            case UNION_SET:
                new_set->arr[i] = setA->arr[i] | setB->arr[i];
                break;
            
            case INTERSECT_SET:
                new_set->arr[i] = setA->arr[i] & setB->arr[i];
                break;

            case SUB_SET:
                new_set->arr[i] = setA->arr[i] & ~(setB->arr[i]);
                break;

            case SYMDIFF_SET:
                new_set->arr[i] = setA->arr[i] ^ setB->arr[i];
                break;
            
            default:
                break;
            }
        }
    }
    return new_set;
}

void print_group(int group, unsigned short int content)
{
    int j;
    for (j = 0; j < SIZE; j++)
    {
        unsigned short int k = (1 << j);
        if (content & k)
        {
            printf("%ld\t", (group * SIZE) + j);
        }
    }
    if (content)
    {
        putchar('\n');
    }
}

void print_set(Set set)
{
    int group;
    for (group = 0; group < SET_SIZE / SIZE; group++)
    {
        print_group(group, set->arr[group]);
    }
}

Set init_set()
{
    Set set = malloc(sizeof(arr));
    return set;
}