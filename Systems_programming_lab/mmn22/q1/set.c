/**
 * PROGRAM: This program makes operation on sets in range [0,127] that represented in bit field.
 */
#include "set.h"

/* adds a num in range [0,127] into set */
void add_to_set(Set *set, unsigned short int num)
{
    int group = num / SIZE;     /* the group of the num */
    int bit_index = num % SIZE; /* bit to change to one */
    (*set)->arr[group] |= (1 << bit_index);
}

/* read set from another set */
void read_set(Set *setA, Set setB)
{
    int i;
    for (i = 0; i < SET_SIZE / SIZE; i++)
        (*setA)->arr[i] = setB->arr[i];
}

/* applying function on two sets, and store the result in third set */
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
            case UNION_SET: /* applying union on the two sets */
                (*setC)->arr[i] = (*setA)->arr[i] | (*setB)->arr[i];
                break;

            case INTERSECT_SET: /* applying intersect on the two sets */
                (*setC)->arr[i] = (*setA)->arr[i] & (*setB)->arr[i];
                break;

            case SUB_SET: /* applying sub on the two sets */
                (*setC)->arr[i] = (*setA)->arr[i] & ~((*setB)->arr[i]);
                break;

            case SYMDIFF_SET: /* applying symdiff on the two sets */
                (*setC)->arr[i] = (*setA)->arr[i] ^ (*setB)->arr[i];
                break;

            default:
                break;
            }
        }
    }
}

/* prints row of the set in line, the max number of element in group is 16 */
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
            printf("%ld\t", (group * SIZE) + j); /* the start number of the group is (group * SIZE) */
        }
    }
    if (content) /* if the group is not empty then we need new line for next group */
    {
        putchar('\n');
    }
    return bits_on;
}

/* prints the set in lines, when the max number of set numbers in row is 16 */
int print_set(Set *set)
{
    int bits_on = 0;
    int group;
    for (group = 0; group < SET_SIZE / SIZE; group++)
    {
        bits_on += print_group(group, (*set)->arr[group]);
    }
    if (!bits_on) /* if nothing was printed */
        printf("The set is empty\n");
    return bits_on;
}

/* initializing empty set (malloc puts zeros in array values) */
Set init_set()
{
    Set set = malloc(sizeof(arr));
    return set;
}